float timedifference_msec(struct timeval t0, struct timeval t1) {
	return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
} 

while (totalMs < 140.0f) {
	gettimeofday(&t0, 0);

	simSetup(); 
	tmpResults = simulate();

	if (tmpResults.points > bestResults.points || (tmpResults.points == bestResults.points && tmpResults.len > bestResults.len)) {
		bestResults = tmpResults;
		newBest = true;
		moveNum = 0;
		simCurrentBest = bestResults.points;
	}

	gettimeofday(&t1, 0);
	totalMs += timedifference_msec(t0, t1);
	simRun++;
}

fprintf(stderr, "total sim run %d in %f ms\n", simRun, totalMs);