print '<twitterMentionMoodLight>'

# import libraries
import twitter
import serial
import time

# connect to arduino via serial port
arduino = serial.Serial('COM4', 9600, timeout=1)

# establish OAuth id with twitter
api = twitter.Api(consumer_key= 'KnhtD9RVeBxaMOZwM72bAHik3',
                  consumer_secret='ldS4zv8kLnXLnABPRElRPwmkm8IPumLIb0GkORbKPMggV4FfEl',
                  access_token_key='FJr9h596FlgYH8ncHvgjOaOQ72efN425IszL86U',
                  access_token_secret='dqNglynYGlsDGQYDhrfFzcBnQ1GJPAuBpIVn0JZ0GonMz')

oldID = "" # used in getMention()

# listen to arduino
def listenToArduino():
    msg=arduino.readline()
    if msg > '':
        print 'arduino msg: '+msg.strip()
        updateStatus(msg.strip())

# search for any mention of @yourUsername
def getMention():
    status = api.GetReplies()
    newID = str(status[0].id)
    global oldID
    if (newID != oldID):
        oldID = newID
        print status[0].text+", by @"+status[0].user.screen_name
        arduino.write(1) # arduino gets 49

# post new message to twitter
def updateStatus(newMsg):
    localtime = time.asctime(time.localtime(time.time()))
    tweet = api.PostUpdate(newMsg+", "+localtime)
    print "tweeted: "+tweet.text

while 1:
    listenToArduino()
    getMention()
    time.sleep(15) # avoid twitter rate limit
