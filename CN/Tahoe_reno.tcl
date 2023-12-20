set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red

# Open the NAM trace file
set file2 [open out.nam w]
$ns namtrace-all $file2

# Open the Window trace file
set winfile [open reno w]

proc finish {} {
  global ns file2
  $ns flush-trace
  close $file2
  exec nam out.nam &
  exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns simplex-link $n2 $n3 0.3Mb 200ms DropTail
$ns simplex-link $n3 $n2 0.3Mb 200ms DropTail
$ns duplex-link $n3 $n4 2Mb 10ms DropTail
$ns duplex-link $n3 $n5 2Mb 10ms DropTail

$ns duplex-link-op $n2 $n3 queuePos 0.1

# Set Queue Size of link (n2-n3) to 10
$ns queue-limit $n2 $n3 10

# Setup a TCP connection
set tcp [new Agent/TCP/Reno]
$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n4 $sink

$ns connect $tcp $sink
$tcp set fid_ 1
$tcp set window_ 8000
$tcp set packetSize_ 552

# Setup a FTP over TCP connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp

# Schedule start/stop times
$ns at 0.1 "$ftp start"
$ns at 100.0 "$ftp stop"

proc plotWindow {TCPSource File} {
    global ns 
    set time 0.1
    set now [$ns now]
    set cwnd [$TCPSource set cwnd_]
    set wnd [$TCPSource set window_]
    puts $File "$now $cwnd"
    $ns at [expr $now+$time] "plotWindow $TCPSource $File"
}

$ns at 0.1 "plotWindow $tcp $winfile"
$ns at 125.0 "finish"

set trace_file [open "tahoe.tr" w]
$ns trace-queue $n2 $n3 $trace_file

$ns run