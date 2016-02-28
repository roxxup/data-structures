from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.common.exceptions import TimeoutException
import time
import requests
from selenium.webdriver.common.action_chains import ActionChains

import os
def get_url(img):
    url = "http://imgup.net/upload"
    data = {'utf8': '&#x2713;', '_method': 'put'}
    f = open(img, "rb")  # open in binary mode
    files = {'image[image][]': f}
    r = requests.post(url, files=files, data=data)
    f.close()
    return (r.json()['direct_link'])
driver = webdriver.Chrome()
driver.get("http://cloudsightapi.com/api")

# wait = WebDriverWait(driver, 10)
# element = wait.until(EC.element_to_be_clickable((By.ID, "dropzoneTarget")))
# driver.execute_script("arguments[0].click();", element)
# try:
#     element = WebDriverWait(driver, 3).until(EC.element_to_be_clickable((By.ID, "dropzoneTarget")))
#     print "Page is ready!"
#     with  open("here.html","w") as f:
#         f.write(driver.page_source.encode("utf-8"))

# except TimeoutException:
#     print "Loading took too much time!"

image_url = ".//*[@id='image_url_form']/p[1]/input"
upload = ".//*[@id='image_url_form']/p[2]/input"
for i in range(0,3):
    imageElement = WebDriverWait(driver, 2).until(lambda driver: driver.find_element_by_xpath(image_url))
    uploadElement = WebDriverWait(driver, 2).until(lambda driver: driver.find_element_by_xpath(upload))
    imageElement.clear() 
    imageElement.send_keys(get_url("example.jpg"))
    uploadElement.click()
    time.sleep(4)




# body.send_keys(Keys.CONTROL + Keys.TAB)
