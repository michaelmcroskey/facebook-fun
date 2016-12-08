# Facebook Fun
Michael McRoskey (mmcrosk1), David Mellitt (dmellitt), Troy Prince (tprince)

----
## Overview
Facebook Fun is a project which collects Facebook friend data from users to construct a visual display of an entire social network and determine the degrees of separation between two people. It runs on a local server via the [SimpleHTTPServer](https://docs.python.org/2/library/simplehttpserver.html) module in Python and utilizes the [D3.js](https://d3js.org/) data visualization framework. It also makes use of the [Facebook Graph API](https://developers.facebook.com/docs/graph-api) to pull in friend data which it persistently stores.

----
## Files
1. **`server.py`**: This contains the script to process and handle server requests on `localhost:9001`. It loads `index.html` as the default page in a web browser.
2. **`Makefile`**: Running the command `make` in this directory will properly compile all the executables for the project.
3. **`dikjstras.cpp`**: This 
4. **`edge.h`**:
5. **`node.h`**:
6. **`graph.h`**:
7. benchmarks
	* **`test.cpp`**:
8. www
	* **`index.html`**:
	* **`style.css`**:
	* **`graph.txt`**:
9. **`README.md`**:
10. **`CONTRIBUTIONS.md`**: 

----
## Usage
1. Run `$ make` to build the executables.
2. Run `$ python server.py` to run the Python server on `localhost:9001`
3. In a web browser, navigate to `http://localhost:9001/`.
4. Follow the instructions to sign in with Facebook, granting the app 'DS Final Project' access to your friends.

*Note: Facebook's Graph API prevents us from pulling entire friend lists from a user. Instead, we can pull a list of friends who have also authorized the app. Thus, we have included a test list of friends:*

| NAME     | EMAIL                                | PASSWORD    |
|----------|--------------------------------------|-------------|
| Michael  | michael_vrpjwss_mcroskey@tfbnw.net   | testing123  |
| David    | david_xbuwunm_mellitt@tfbnw.net      | testing123  |
| Troy     | troy_iricmpf_prince@tfbnw.net        | testing123  |

*You can login to Facebook with these people on [www.facebook.com](http://www.facebook.com/) and verify their friends are correctly connected. However, the included `graph.txt` should already have a pre-built network based on test profiles of the London Data Structures section.*

Explain how signing in with one person will first build initial nodes, signing in with next, ... slowly building social network
Sign out?!

5. To check if two people are friends or how many degrees away they are from each other, type a first name into the 'Start Node' field and another first name into the 'End Node' field and click 'GO'.
6. If a path exists, the webpage will generate a graph highlighting the edges between the specified nodes within a larger social network.



----
## Benchmarking

Using makeFriends.sh to create input files, we ran measure on testGraph.cpp, a more input friendly version of dijkstras.cpp. testGraph takes input as "source target" instead of the JSON file and creates an undirected edge.

| People        | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | 0.001530      | 0.835938       |
| 30            | 0.001721      | 0.843750       |
| 50            | 0.001957      | 0.875000       |
| 70            | 0.002125      | 0.882812       |
| 90            | 0.002236      | 0.898438       |
| 110           | 0.002362      | 0.902344       |
| 130           | 0.002687      | 0.914062       |
| 150           | 0.002746      | 0.921875       |
|---------------|---------------|----------------|


[Benchmarked with 150 nodes!](http://imgur.com/a/jaZyP)

----
## Known Issues
As any good programming team would do, we wanted to highlight some known issues to prevent confusion about certain aspects of the program.

1. Signing out - we have no function to sign out. Users must open a new Facebook tab and sign out through their interface.
2. It really only works with a limited amount of users because of Facebook's API which restricts information sent to us--we are only allowed access to friends who have also authorized the app.
3. As of now, the most inputs the program can take is 1000000 because that is the number of iterations dijkstras runs through before determining that two nodes are not connected (otherwise when two nodes are not connected there would be an infinite loop). 


----

Contributions
=============

Michael McRoskey: Python server and Javascript implementation

David Mellitt: Debugging, benchmarking

Troy Prince: s

----
## markdown quick reference
# headers

*emphasis*

**strong**

* list

>block quote

	code (4 spaces indent)
[links](http://wikipedia.org)
