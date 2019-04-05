class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {

       auto log_comp = [](auto& l, auto& r)->bool 
                       { 
                           if(l.substr(l.find_first_of(" ") + 1) == r.substr(r.find_first_of(" ") + 1))
                               return l < r;

                           return l.substr(l.find_first_of(" ") + 1) <
                                  r.substr(r.find_first_of(" ") + 1);
                       };

        std::set<std::string, decltype(log_comp)> letter_logs(log_comp);
        std::vector<std::string> ret;

        for(std::vector<std::string>::iterator it = logs.begin(); it != logs.end();) {
            std::istringstream iss(*it);
            std::string temp;

            iss >> temp;
            iss >> temp;

            if(temp[0] >= '0' && temp[0] <= '9') {
                ++it;
                continue;
            }

            letter_logs.insert(*it);
            it = logs.erase(it);
        }

        std::copy(letter_logs.begin(), letter_logs.end(), std::back_inserter(ret));
        std::copy(logs.begin(), logs.end(), std::back_inserter(ret));

        return ret;
    }
};
