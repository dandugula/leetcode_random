class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::vector<bool> visited_rooms(rooms.size(), false);
        std::queue<int> breadth_queue;
        
        breadth_queue.push(0);
        visited_rooms[0] = true;

        do {
            int room = breadth_queue.front();
            breadth_queue.pop();
            for(auto aKey : rooms[room]) {
                if(!visited_rooms[aKey]) {
                    visited_rooms[aKey] = true;
                    breadth_queue.push(aKey);
                }
            }
        } while(!breadth_queue.empty());

        return std::find(std::begin(visited_rooms), std::end(visited_rooms), false) 
               == std::end(visited_rooms) ? true : false; 
    }
};
