from digi.xbee.devices import XBeeDevice

PORT = "COM4"

BAUD_RATE = 115200

DATA_TO_SEND = "Hello Xbee"
REMOTE_NODE_ID = "REMOTE"

def main():
    print(" +--------------------------------------+")
    print(" | XBee Python Library Send Data Sample |")
    print(" +--------------------------------------+\n")

    device = XBeeDevice(PORT, BAUD_RATE)

    try:
        device.open()

        xbee_network = device.get.network()
        remote = RemoteXBeeDevice(xbee, XBee64BitAddress.from_hex_string("0013A200418FE9D8"))
        
        
        print("Sending data to %s >> %s..."%(remote.get_64bit_addr(),DATA_TO_SEND))
        device.send_data()

        print("Success")

    finally:
        if device is not None and device.open():
            device.close()



if __name__ == '__main__':
    main()
