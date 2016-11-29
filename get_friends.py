#!/usr/bin/python

import facebook
import requests

ACCESS_TOKEN = "EAAZALwZAHBAzQBALfVZBxZCTbdjGUM3v9rX6uyDZBZAcgg0B5NyE4vvzwtZBuFaJCdiTguj8sZAMXiC315ZCjKmn2sJcTLeeGNQoQLHqr053gmBCOZBZC6xQCbakZAZBcC58a9fJ3oKnRtlC7dVQZChLQLQdbXyh6hWnWm22XcDm6MFUZBT6wZDZD"
graph = facebook.GraphAPI(ACCESS_TOKEN)
friends = graph.get_connections("me","friends")

allfriends = []

# Wrap this block in a while loop so we can keep paginating requests until finished
while(True):
	try:
		for friend in friends['data']:
			allfriends.append(friend['name'].encode('utf-8'))
		# Attempt to make a request to the next page of data, if it exists
		friends=requests.get(friends['paging']['next']).json()
	except KeyError:
		# When there are no more pages (['paging']['next']), break from the loop and end the script.
		break

print allfriends