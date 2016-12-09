# Facebook Fun
Michael McRoskey (mmcrosk1), David Mellitt (dmellitt), Troy Prince (tprince)

[CHECK OUT THE DEMO VIDEO!](https://www.youtube.com/watch?v=GIUmYVA717M)

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
| Shreya   | shreya_oomfjvh_kumar@tfbnw.net       | testing123  |

*You can login to Facebook with these people on [www.facebook.com](http://www.facebook.com/) and verify their friends are correctly connected. However, the included `graph.txt` should already have a pre-built network based on test profiles of the London Data Structures section. You can also test out `graph-random.txt` for a graph of 150 randomly generated nodes (via `testGraph.cpp`).*

Signing in as a user will append all those users friends (who have approved the app) to the `graph.txt` file. When another person signs in, it adds their friends, and so on. When enough people have added friends, a more connected graph will emerge.

5. To check if two people are friends or how many degrees away they are from each other, type a first name into the 'Start Node' field and another first name into the 'End Node' field and click 'GO'.
6. If a path exists, the webpage will generate a graph highlighting the edges between the specified nodes within a larger social network. Otherwise, it should output an error if:

- The start and end are the same node
- A user doesn't exist in the graph
- Both users don't exist in the graph
- In the event of a disconnected graph (no mutual friends), it will still display but obviously not display a connection between the disconnected nodes

----
## Benchmarking

Using makeFriends.sh to create input files, we ran measure on testGraph.cpp, a more input friendly version of dijkstras.cpp. testGraph takes input as "source target" instead of the JSON file and creates an undirected edge.

| People        | Elapsed Time   | Memory Usage     |
|---------------|----------------|------------------|
| 10            |  0.001411      |   0.835938       |
| 100           |  0.002383      |   0.878750       |
| 1000          |  0.010753      |   1.300781       |
| 10000         |  0.104035      |   5.682812       |
| 100000        |  1.045944      |  45.570312       |
| 1000000       | 11.411662      | 519.390625       |
|---------------|----------------|------------------|

Memory usage was proportional to nodes, which was expected. The elapsed time also seemed to grow proportional to nodes, although Dijkstra's is O(n^2). It helps that the algorithm stops once target is found.

*Note: we deleted the largest two sample input files because of their size.*

[Benchmarked with 150 nodes!](http://imgur.com/a/jaZyP)

----
## Known Issues
As any good programming team would do, we wanted to highlight some known issues to prevent confusion about certain aspects of the program.

1. Signing out - we have no function to sign out. Users must open a new Facebook tab and sign out through their interface.
2. It really only works with a limited amount of users because of Facebook's API which restricts information sent to us--we are only allowed access to friends who have also authorized the app.
3. As of now, the most inputs the program can take is 1000000 because that is the number of iterations dijkstras runs through before determining that two nodes are not connected (otherwise when two nodes are not connected there would be an infinite loop). 
4. We rely only on first names as node identifiers. In a market build, we would likely base nodes off of unique Facebook user IDs.

----

Contributions
=============

Michael McRoskey: Python server and Javascript implementation

David Mellitt: Debugging, benchmarking

Troy Prince: Dijkstra's, graph management, testing
