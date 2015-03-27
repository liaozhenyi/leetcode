/**********************************************************************

 Given a set of non-overlapping intervals, insert a new interval into the 
 intervals (merge if necessary).

 You may assume that the intervals were initially sorted according to their 
 start times.

 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as 
 [1,2],[3,10],[12,16].
 
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

**********************************************************************/

/*
 * Use low, high record new interval to add which contains newInterval,
 */
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	int i, j, k;
	int low = newInterval.start, high = newInterval.end;
	vector<Interval> ans;
	
	for (i = 0; i < intervals.size(); i++) {
		if (newInterval.start < intervals[i].start) {
			low = newInterval.start;
			break;
		} else if (newInterval.start > intervals[i].end) {
			ans.push_back(intervals[i]);
		} else {
			low = intervals[i].start;
			break;
		}
	}

	for (j = i; j < intervals.size(); j++) {
		if (newInterval.end < intervals[j].start) {
			high = newInterval.end;
			break;
		} else if (newInterval.end >= intervals[j].start && \
				newInterval.end <= intervals[j].end) {
			high = intervals[j].end;
			++j;
			break;
		}
	}
	ans.push_back(Interval(low, high));

	for (k = j; k < intervals.size(); k++) {
		ans.push_back(intervals[k]);
	}

	return ans;
}
