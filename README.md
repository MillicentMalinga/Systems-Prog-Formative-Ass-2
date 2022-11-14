# ELEVATOR SIMULATOR 

This program is an elevator simulator using threads. 

Current issues:
1. The offloading of passengers is not waiting for each user to land first
2. Entering destinations is running concurrently and not waiting for completion hence there is a mess. 

POSSIBLE SOLUTIONS
1. Implement barriers to ensure that each rider gets off the elevator at their destination floor

