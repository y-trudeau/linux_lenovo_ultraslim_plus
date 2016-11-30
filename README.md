Linux driver for Lenovo Ultraslim Plus combo
============================================

Recently one of my daughter bought a Lenovo Ultraslim plus keyboard and mouse combo. She's a long time Linux user, an apple never falls far from the apple tree.  She connected the dongle and although the mouse worked correctly, the keyboard was not.  We tried on my computer, another Linux box, and still not working.  We thought the keyboard was broken and even called Lenovo support but at some point we tried on a Windows box.  Windows searched for a driver a long time and eventually found one and the keyboard was working.  That was disapointing...

I plugged the dongle back to my computer and loaded the usbmon kernel modules and started looking at the output from the keyboard.  It is "almost" the same as a regular USB keyboard but each line ends with a "0x71" which apparently causes the Linux hid driver to fail understanding the output.  Here's a sample:



Having a few hours free, quite a few... I wrote the following driver.  I didn't want to mess with libusb so I went straight to the usbmon output and reinjected the keyboard events in the uinput facility.  

Installation
------------

- Compile the driver with: gcc -o kbdusb kbdusb.c
- Copy kbdusb and lenovo_keyboard.sh to /usr/local/bin 
- Copy 85-lenovo-keyboard.rules to the udev rules directly, on Ubuntu 16.04, it is /lib/udev/rules.d/
- reload udev rules with: udevadm control --reload-rules
- plug the dongle and it should work...

If not working
--------------

Ubuntu have the uinput device at /dev/uinput, it seems that some Linux distro have it at /dev/uinput/uinput, just change the path in the source it if your case.  I found it useful to modify the udev rule line calling the script like:

    ATTRS{idVendor}=="17ef", ATTRS{idProduct}=="609b", RUN+="/bin/bash -x /usr/local/bin/lenovo_keyboard.sh 2> /tmp/kbd.trace  &"

Look at the trace file if you can identify what is causing the error.  Finally, you can enable the DEBUG variable in the source and recompile.  With debug, you can run the lenovo_keyboard.sh script in foreground. 
