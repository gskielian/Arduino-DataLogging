GNU-Screen
==========


This is a simple method which doesn't even require python.


## Two Simple Steps


**First**, add the following to your `~/.screenrc` file using your favorite text editor (I use `vim`):

```bash
logtstamp on
logtstamp after 0.5
logfile flush 0.5
logfile "screenlog.%t.%1`"
log on
```

And 2) type in the following:


`screen -L /dev/tty.usbmodem9999`  instead of /dev/tty.usbmodem9999, use the serial port it says on the bottom right corner of the Arduino ide.


this is now logging timestamps with your data!  However, this is not as great perhaps as you might want it, as the time-stamps are not in line with your Serial Output.





