## Requirements: 
- Code Base: Organisation 90%, Efficiency 80%, Execution 90%, Goals, 90%
	- [x] Code written in cpp and can run on EWS, 
	- [ ] Command line interface, altering input output locations
	- [ ] No obvious inefficiency
		- Dijkstra efficiency problems. I believe the efficiency problem is really similar to the one that another group had, so I've copied the explanation that Professor Solomon provided, to clear things up.
>On code efficiency: Dijkstras does not match the proposed efficiency -- instead of O(E log V), your solution is O( E * (V log (E))). The main problem here is that your priority queue can have E total objects inserted and processed -- the first time you go from infinity to not infinity but then potentially every subsequent edge can be an 'improvement' to some vertex. A test case example to consider is a totally connected graph where all edges are (infinity - 1) except one edge which is 1 and repeat this process for that new node. Let that new node have edges (infinity - 3) except one edge 1 (that connects to a third node...). Every time you pick the new minimum (dist 1, 2, 3, ...) you are also updating all your other vertices you havent seen from inf to inf-1, inf-2, inf-3, ... You can start to already see how this will cause a problem -- your priority queue is going to add a new object for *every* edge and your code doesn't remove or replace the 'old' version! 
>Meanwhile, your inner loop will run a total of V times in the worst case (totally connected graph) and the built-in runtime of the priority queue push is log(n) where n is the size of the queue. Which, as has already been pointed out, is not V but (E). So the total runtime is (V log (E)). Combined with the fact that the outer loop can call the same vertex multiple times (one for each edge!) and this is significantly more inefficient then proposed.
>
>To achieve better performance you would need to update the existing values in your priority queue rather than push new values in.

- bad usage of the using keyword,
		- `using namespace std;`, can import  function, variable declarations that might clash with what you've already declared.

	- [x] Can run on entire proposed dataset
	- [ ] Appropriately named variables, classes, functions,
		- multiple variables have been given names like, a , b , x ,y , vect...
		- names should contain more information about what they represent.
		- functions have been properly named.
	- [ ] Organized comments detailing input, output, and intended behaviour
		- most functions have been commented,
		- inconsistent commenting - function docstring missing from some functions, function body comments missing from some functions.
	- [x] No unnecessary code
	- [ ] Can run all proposed algorithms and have tests for all proposed algorithms that prove that it works
		- Runs all proposed algorithms.
		- Test cases don't properly check file reading, checking that all node values are positive is not enough
		- Test cases don't check all edge cases for adding nodes to graph objects.(really small sample sizes)
		- bounds check bug in addEdge. (0 < start < u_bound).
		- same functionality tested twice with same context/scope. (RoadNetwork addEdge tests)
		- shortestPath tests small, edge cases but no large tests,.
		- SCC small tests, edge cases, but no large tests.
- README: 90%
	- [x] Describes the physical location of all major deliverables
		-  Written report, video, code, output, input and test locations present
	- [ ] Instructions on building and running executable, testing suite
		- Instructions present, but  not clear.
	- [ ] How to define input, output data,
		- Missing
	- [x] A general description of tests.
- Written Report :  90% 
	- [ ] Contains some summary of some part of the full scale run for each algorithm
		- Summary of algorithms exist but do not contain any information about the full scale run and its results.
		- Dijkstra Complexity is not accurate.
	- [x] Describes which tests were performed to show that each algorithm worked
	- [ ] Directly addresses leading question, how was it answered, what was discovered? If unsuccessfull what worked and what didn't?
		- No mention of what result was reached by doing this analysis on the proposed dataset.
		- The leading question of how can we find shortest path, and how can we find an area of concentration is answered with algos.
- Final Presentation : Content 80%, Skills 90%
	- [ ] Video less than 10 mins
		- Video is 17 mins.
	- [x] Video has summary of goals and what was accomplished
	- [x] Video has high level overview of the work put in.
	- [x] Video has an ending that explains the leading question
	- [ ]  Individual thoughts.
		-  Video is missing individual thoughts. which is fine, but the screen recording for one team member seems to have failed/ is not present.


#### Note : 
-  A crossed through requirement indicates that that particular requirement was fulfilled.(100%)
