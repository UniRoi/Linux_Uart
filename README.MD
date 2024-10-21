# Assignment 5.1

## Part 1
After opening minicom 

    pi@rpi-matthiasr24:~ $ stty -a -F /dev/ttyS0 
    speed 115200 baud; rows 0; columns 0; line = 0;
    intr = <undef>; quit = <undef>; erase = <undef>; kill = <undef>; eof = <undef>; eol = <undef>; eol2 = <undef>; swtch = <undef>; start = <undef>; stop = <undef>;
    susp = <undef>; rprnt = <undef>; werase = <undef>; lnext = <undef>; discard = <undef>; min = 1; time = 5;
    -parenb -parodd -cmspar cs8 hupcl -cstopb cread clocal crtscts
    ignbrk -brkint -ignpar -parmrk -inpck -istrip -inlcr -igncr -icrnl -ixon -ixoff -iuclc -ixany -imaxbel -iutf8
    -opost -olcuc -ocrnl -onlcr -onocr -onlret -ofill -ofdel nl0 cr0 tab0 bs0 vt0 ff0
    -isig -icanon -iexten -echo -echoe -echok -echonl -noflsh -xcase -tostop -echoprt -echoctl -echoke -flusho -extproc

After setting speed to 1200 baud

    pi@rpi-matthiasr24:~ $ stty -a -F /dev/ttyS0 
    speed 1200 baud; rows 0; columns 0; line = 0;
    intr = <undef>; quit = <undef>; erase = <undef>; kill = <undef>; eof = <undef>; eol = <undef>; eol2 = <undef>; swtch = <undef>; start = <undef>; stop = <undef>;
    susp = <undef>; rprnt = <undef>; werase = <undef>; lnext = <undef>; discard = <undef>; min = 1; time = 5;
    -parenb -parodd -cmspar cs8 hupcl -cstopb cread clocal crtscts
    ignbrk -brkint -ignpar -parmrk -inpck -istrip -inlcr -igncr -icrnl -ixon -ixoff -iuclc -ixany -imaxbel -iutf8
    -opost -olcuc -ocrnl -onlcr -onocr -onlret -ofill -ofdel nl0 cr0 tab0 bs0 vt0 ff0
    -isig -icanon -iexten -echo -echoe -echok -echonl -noflsh -xcase -tostop -echoprt -echoctl -echoke -flusho -extproc


## Part 2

compile example with

    gcc -o uart_test Uart_test.cpp 

Concole output:

    pi@rpi-matthiasr24:~/Linux_Uart/p2 $ gcc -o uart_test Uart_test.cpp 
    pi@rpi-matthiasr24:~/Linux_Uart/p2 $ ./uart_test 
    The following was read in [20]: Hello Raspberry Pi!
    pi@rpi-matthiasr24:~/Linux_Uart/p2 $

After adding newline character to the end of the string the following output is received:

    pi@rpi-matthiasr24:~/Linux_Uart/p2 $ ./uart_test 
    The following was read in [22]: Hello Raspberry Pi!

    pi@rpi-matthiasr24:~/Linux_Uart/p2 $

A newline is printed because of the \n, I also increased the length of the write to 22 characters