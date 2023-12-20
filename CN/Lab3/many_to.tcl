set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red
$ns color 3 Green

set nf [open out.nam w]
$ns namtrace-all $nf

proc finish {} {
    global ns nf
    $nf flush-trace
    close $nf
    exec nam out.nam &
    exit 0
}

set wiredNode(1) [$ns node]
set wiredNode(2) [$ns node]
set wiredNode(3) [$ns node]
set wiredNode(4) [$ns node]

set wiredLink(1) [$ns duplex-link $wiredNode(1) $wiredNode(2) 10Mb 10ms Droptail]
set wiredLink(2) [$ns duplex-link $wiredNode(2) $wiredNode(3) 10Mb 10ms Droptail]
set wiredLink(3) [$ns duplex-link $wiredNode(3) $wiredNode(4) 10Mb 10ms Droptail]

set udp1 [new Agent/UDP]
$ns attach-agent $wiredNode(1) $udp1
set null1 [new Agent/Null]
$ns attach-agent $wiredNode(2) $null1
$ns connect $udp1 $null1
$udp1 set fid_ 1

set udp2 [new Agent/UDP]
$ns attach-agent $wiredNode(3) $udp2
set null2 [new Agent/Null]
$ns attach-agent $wiredNode(2) $null2
$ns connect $udp2 $null2
$udp2 set fid_ 2

set udp3 [new Agent/UDP]
$ns attach-agent $wiredNode(4) $udp3
set null3 [new Agent/Null]
$ns attach-agent $wiredNode(2) $null3
$ns connect $udp3 $null3
$udp3 set fid_ 3


set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
$cbr1 set type_CBR
$cbr1 set packet_size_ 1000
$cbr1 set rate_ false
$ns at 0.5 "$cbr1 start"
$ns at 4.5 "$cbr1 stop"

set cbr2 [new Application/Traffic/CBR]
$cbr2 attach-agent $udp2
$cbr2 set type_CBR
$cbr2 set packet_size_ 1000
$cbr2 set rate_ false
$ns at 0.5 "$cbr2 start"
$ns at 4.5 "$cbr2 stop"

set cbr3 [new Application/Traffic/CBR]
$cbr3 attach-agent $udp3
$cbr3 set type_CBR
$cbr3 set packet_size_ 1000
$cbr3 set rate_ false
$ns at 0.5 "$cbr3 start"
$ns at 4.5 "$cbr3 stop"

$ns at 5.0 "finish"

$ns run
