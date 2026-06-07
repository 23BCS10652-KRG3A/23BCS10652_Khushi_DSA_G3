class MyCalendarTwo {
public:
    vector<pair<int,int>> books;
    vector<pair<int,int>> overlaps;

    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        for (auto &p : overlaps) {
            if (max(start, p.first) < min(end, p.second))
                return false;
        }

        for (auto &p : books) {
            int l = max(start, p.first);
            int r = min(end, p.second);

            if (l < r)
                overlaps.push_back({l, r});
        }

        books.push_back({start, end});
        return true;
    }
};
