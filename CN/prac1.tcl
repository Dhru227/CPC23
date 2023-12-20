set ns [new Simulator]
set nf [open out.nam w]
$ns namtrace-all $nf

set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]


$ns duplex-link $n1 $n2  1Mb 10ms DropTail
$ns duplex-link $n2 $n3  1Mb 10ms DropTail
$ns duplex-link $n3 $n4  1Mb 10ms DropTail


set tcp [new Agent/TCP]
$ns attach-agent $n1 $tcp

set tcp [new Agent/TCP]
$ns attach-agent $n2 $tcp

set tcp [new Agent/TCP]
$ns attach-agent $n3 $tcp


set sink1 [new Agent/TCPSink]
$ns attach-agent $n2 $sink1
$ns connect $tcp $sink1

set sink2 [new Agent/TCPSink]
$ns attach-agent $n3 $sink2
$ns connect $tcp $sink2

set sink3 [new Agent/TCPSink]
$ns attach-agent $n4 $sink3
$ns connect $tcp $sink3


set cbr1 [new Application/Traffic/CBR]
    $cbr1 attach-agent $tcp
    $cbr1 set packet_size_ 1000
    $cbr1 set rate_ 1mb
    $cbr1 set random_ false

set cbr2 [new Application/Traffic/CBR]
    $cbr2 attach-agent $tcp
    $cbr2 set packet_size_ 1000
    $cbr2 set rate_ 1mb
    $cbr2 set random_ false

set cbr3 [new Application/Traffic/CBR]
    $cbr3 attach-agent $tcp
    $cbr3 set packet_size_ 1000
    $cbr3 set rate_ 1mb
    $cbr3 set random_ false

set cbr4 [new Application/Traffic/CBR]
    $cbr4 attach-agent $tcp
    $cbr4 set packet_size_ 1000
    $cbr4 set rate_ 1mb
    $cbr4 set random_ false   


    $ns at 0.0 "$cbr1 start"
    $ns at 3.0 "$cbr2 stop" 
    $ns at 3.5 "$cbr2 start"

    $ns at 4.0 "$cbr3 stop" 
    $ns at 4.5 "$cbr3 start"
    $ns at 5.0 "$cbr4 stop"

proc finish {} {
    global ns nf
    $ns flush-trace
    close $nf
    exec nam out.nam &
    exit 0
}

$ns at 10.0 "finish"
$ns run          