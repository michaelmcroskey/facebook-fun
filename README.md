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
## Dependencies
Our project requires the [Facebook Graph API](https://developers.facebook.com/docs/graph-api) which we did not include in the root directory since we run it in a virtual environment via [VirtualENV](http://docs.python-guide.org/en/latest/dev/virtualenvs/). To properly set up the environment, please fork the repository and then follow these steps:

	$ pip install virtualenv
	$ cd facebook-fun
	$ virtualenv -p /usr/bin/python2.7 facebookenv
	$ source facebookenv/bin/activate
	$ pip install requests
	$ pip install facebook-sdk

This allows the `import facebook` line in `server.py` to properly execute. (wait but actually isn't everything through the javascript SDK?) 

When you are ready to close the virtual environment, you can do so with:

	$ deactivate


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

5. To check if two people are friends or how many degrees away they are from each other, type a first name into the 'Start Node' field and another first name into the 'End Node' field and click 'GO'.
6. If a path exists, the webpage will generate a graph highlighting the edges between the specified nodes within a larger social network.


----
## markdown quick reference
# headers

*emphasis*

**strong**

* list

>block quote

	code (4 spaces indent)
[links](http://wikipedia.org)
