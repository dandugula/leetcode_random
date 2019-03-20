class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        typedef std::pair<int, int> coOrd;
        auto dist_cmp = [](auto l, auto r) {
            return (l.first * l.first + l.second * l.second) >
                   (r.first * r.first + r.second * r.second);
        };

        std::priority_queue<coOrd, std::vector<coOrd>, decltype(dist_cmp)> closest_queue(dist_cmp);
        std::vector<std::vector<int>> ret;

        std::for_each(points.begin(), points.end(), [&closest_queue](auto aPoint) {
            closest_queue.push(std::make_pair(aPoint[0], aPoint[1]));
        });

        for(int i = 0; i < K; ++i) {
            std::pair<int, int> aPoint = closest_queue.top();
            closest_queue.pop();

            ret.push_back({aPoint.first, aPoint.second});
        }

        return ret;
    }
};
