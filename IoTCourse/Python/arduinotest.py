import pyfirmata

import time

if __name__=='__main__':
    board = pyfirmata.Arduino('/dev/ttyACM1')
    print("Board connected successfully")

    while True:
        # board.digital[13].write(1)
        # time.sleep(1)

        for i in range(0,10):
            if i % 2 == 0:
                board.digital[13].write(1)
                print("The value is Even:" ,i)
                time.sleep(1)
            else:
                board.digital[13].write(0)
                print("The value is ODD")
                time.sleep(1)

        #
        # board.digital[13].write(0)
        # time.sleep(0)