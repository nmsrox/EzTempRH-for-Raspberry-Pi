# #
# The MIT License (MIT)
# 
# Copyright (c) 2014 CAIMANICS (hola@caimanics.com)
# Author: Pablo Bacho (pablo.bacho@caimanics.com)
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# #

import serial

ser = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)

ser.write("c")

s = ser.read(3)

temperature = ord(s[1])
print 'Temperature: ' + str(1.0*temperature) + 'C'

#humidity = (ord(s[3]) << 8) + ord(s[4])
#print 'Humidity:    ' + str(humidity) + '%'

#external = (ord(s[5]) << 8) + ord(s[6])
#print 'External:    ' + str(external) + ' / 2048 counts'

ser.close()
