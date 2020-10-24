import time

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import NoSuchElementException

browser = webdriver.Chrome(executable_path="C:\\Users\\rahul negi\\Downloads\\whatsappBomber-master\\chromedriver.exe")
browser.get('https://web.whatsapp.com')
time.sleep(15)
flag = 1
while(flag == 1):
    targett = input('Enter name of contact:')
    target_name = '//span[@title="' + targett + '"]'
    try:
        browser.find_element_by_class_name('_2heX1').click()
        time.sleep(1)
    except:
        pass
    search = browser.find_element_by_class_name('eiCXe')
    search.send_keys(targett)
    time.sleep(7)
    browser.find_element_by_xpath(target_name).click()
    input_box = browser.find_element_by_class_name('_13mgZ')

    n = int(input('Enter the number of texts you want to send:'))
    message = input('Enter your message:')
    for i in range(n):
        input_box.send_keys(message + Keys.ENTER)
    flag = int(input('Enter 1 to do it again or 0 to quit.'))