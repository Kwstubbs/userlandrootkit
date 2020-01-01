# userlandrootkit
Malicious Linux Library Used as Userland Rootkit\n
This library will hide itself from common binaries such as lsof, ls, ps, netstat etc... using the old technique placing library in /etc/ld.so.preload.\n
Sends a GET request to a attacker controlled website to regex for a triggerword that will spawn a reverse shell to the attacker.\n
I found this to be more interesting than failed ssh requests which may seem suspicious.

