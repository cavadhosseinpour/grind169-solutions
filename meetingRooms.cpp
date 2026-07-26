#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

/**
 * @file MeetingRooms.cpp
 * @brief Solution for LeetCode 252 - Meeting Rooms.
 * 
 * Foundational Algorithmic Insights:
 * 1. Sorting Strategy: By sorting intervals chronologically by start time, 
 *    the search space becomes a linear timeline where overlapping segments
 *    must look strictly adjacent. A single linear pass can determine validity.
 * 2. Event Timeline Strategy: Splitting intervals into independent "+1" (Start) 
 *    and "-1" (End) discrete events allows us to process changes chronologically.
 *    Using an ordered map keeps events sorted, allowing a rolling count to reveal 
 *    if active bookings ever breach the maximum capacity threshold of 1.
 * 
 * Complexity Metrics:
 * - Sorting Approach:
 *   - Time Complexity: O(N log N) -> Dominated by the std::sort operation.
 *   - Space Complexity: O(1) or O(N) -> Depends on compiler implementation of std::sort.
 * - Map Timeline Approach:
 *   - Time Complexity: O(N log N) -> Each interval insertion into std::map takes O(log N).
 *   - Space Complexity: O(N) -> Allocates map nodes proportional to the unique time events.
 */

class Solution
{
public:
    /**
     * @brief Determines if a person can attend all meetings using chronological sorting.
     * @param meetings A collection of time intervals where meetings[i] = [start, end].
     * @return true if no meetings overlap, false otherwise.
     */
    bool canAttendMeetings(std::vector<std::vector<int>>& meetings)
    {
        if (meetings.empty()) return true;
        std::sort(meetings.begin(), meetings.end());
        int meetings_count = meetings.size();
        for (int i = 0; i != meetings_count - 1; ++i)
        {
            if (meetings[i + 1][0] < meetings[i][1])
            {
                return false;
            }
        }
        return true;
    }



    // Alternative approach
    // The only issue is that we don't know the time constraints of the problem,
    // so the timeline array allocation is such that it only works for time < 1000.
    bool canAttendMeetings_array(std::vector<std::vector<int>>& meetings)
    {
        int timeline[1001] {0};
        for (int i = 0; i < meetings.size(); ++i)
        {
            timeline[meetings[i][0]] += 1;
            timeline[meetings[i][1]] -= 1;
        }
        int active_meetings {0};
        for (int i = 0; i != 1001; ++i)
        {
            active_meetings += timeline[i];
            if (active_meetings > 1)
            {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief Determines if a person can attend all meetings using an ordered event timeline map.
     * @param meetings A collection of time intervals where meetings[i] = [start, end].
     * @return true if no meetings overlap, false otherwise.
     */
        // Another Alternative approach using std::map
    bool canAttendMeetings_map(std::vector<std::vector<int>>& meetings)
    {
        if (meetings.empty()) return true;
        std::map<int, int> timeline_map;
        for (int i = 0; i != meetings.size(); ++i)
        {
            timeline_map[meetings[i][0]]++;
            timeline_map[meetings[i][1]]--;
        }

        int active_meetings = 0;

        for (const auto [time, change] : timeline_map)
        {
            active_meetings += change;
            if (active_meetings > 1)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    std::vector<std::vector<int>> meetings {{0, 30}, {5, 10}, {15, 20}};
    std::cout << (sol.canAttendMeetings(meetings) ? "No Overlap!" : "Overlap!") << std::endl;
    std::cout << (sol.canAttendMeetings_array(meetings) ? "No Overlap!" : "Overlap!") << std::endl;
    std::cout << (sol.canAttendMeetings_map(meetings) ? "No Overlap!" : "Overlap!") << std::endl;
}