set ns [new Simulator]
set nf [open out.nam w]
$ns namtrace-all $nf

set n(1) [$ns node]
set n(2) [$ns node]
set n(3) [$ns node]
set n(4) [$ns node]

for {set i 2} {$i < 5} {incr i} {
    $ns duplex-link $n(1) $n($i) 1Mb 10ms DropTail
    set tcp($i) [new Agent/TCP]
    $ns attach-agent $n($i) $tcp($i)
    set sink($i) [new Agent/TCPSink]
    $ns attach-agent $n(1) $sink($i)
    $ns connect $tcp($i) $sink($i)

    set cbr($i) [new Application/Traffic/CBR]
    $cbr($i) attach-agent $tcp($i)
    $cbr($i) set packet_size_ 1000
    $cbr($i) set rate_ 1mb
    $cbr($i) set random_ false

    $ns at 0.0 "$cbr($i) start"
    $ns at 3.0 "$cbr($i) stop"   
}

proc finish {} {
    global ns nf
    $ns flush-trace
    close $nf
    exec nam out.nam &
    exit 0
}

$ns at 10.0 "finish"
$ns run