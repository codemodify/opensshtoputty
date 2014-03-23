
### What is it
Converts OpenSSH key format to Putty

### Orinal
http://ukoreh.github.io -> Hacks -> OpenSSH to Putty

### How it works
I did little investigation in putty's code and extracted the code 
that does the converting, made another project and added new commandline 
parameters that will permit you to do this from a batch process without user's intervention.

The source code for patched putty-suite is http://ukoreh.github.io/hacks/putty-0.60.zip, 
it contains the patched converting engine. The archive is a full source code of the putty.

### To do it Yourself
To do it by yourself with a newer version of the PuTTY follow this: 
* download the latest putty sources 
* copy the "windows/automation-feature.c" from the archive above into newly downloaded putty source 
* modify the "windows/winpgen.c" from your putty source as in "windows/winpgen.c" from the archive above. 
* to compile open the "windows/MSVC/putty.dsw" 
* now you must have a working "puttygen.exe" that will do only the converting from putty -> openssh DSA key format. 
