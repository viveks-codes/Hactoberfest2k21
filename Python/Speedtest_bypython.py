# Python program to test
# internet speed

import speedtest

st = speedtest.Speedtest()

option = int(input("what do you want to check: 1. Download speed 2. Upload speed 3. Ping" ))

if option == 1:
    print(st.download())

elif option == 2:
    print(st.upload())

elif option == 3:
    servernames = []
    st.get_servers(servernames)
    print(st.results.ping)

else:
    print("Please choose a correct option")
