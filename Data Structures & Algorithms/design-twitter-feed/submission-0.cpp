class Twitter {
private:
    // follower -> set of followees
    unordered_map<int, unordered_set<int>> following;

    // user -> {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    int time;

public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        // max heap:
        // {timestamp, tweetId, userId, index}
        priority_queue<
            tuple<int, int, int, int>
        > pq;

        // Users whose tweets we need to consider
        vector<int> users;

        // Own tweets
        users.push_back(userId);

        // Followed users
        for (int followee : following[userId]) {
            users.push_back(followee);
        }

        // Put the most recent tweet of each user into heap
        for (int user : users) {
            if (!tweets[user].empty()) {
                int index = tweets[user].size() - 1;

                auto [timestamp, tweetId] = tweets[user][index];

                pq.push({timestamp, tweetId, user, index});
            }
        }

        vector<int> result;

        // Get at most 10 newest tweets
        while (!pq.empty() && result.size() < 10) {

            auto [timestamp, tweetId, user, index] = pq.top();
            pq.pop();

            result.push_back(tweetId);

            // Move to the previous tweet of the same user
            if (index > 0) {
                index--;

                auto [prevTime, prevTweetId] = tweets[user][index];

                pq.push({
                    prevTime,
                    prevTweetId,
                    user,
                    index
                });
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};