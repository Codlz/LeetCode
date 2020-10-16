
// @Title: 单词接龙 (Word Ladder)
// @Author: 554216885@qq.com
// @Date: 2020-10-16 00:58:20
// @Runtime: 168 ms
// @Memory: 26.1 MB

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> wordList)
    {   
        //使用字符串哈希，只相差一个字符的字符串放在vector中
        wordList.push_back(beginWord);

        int l = wordList.size();
        unordered_map<string, vector<int> > _map;
        vector<bool> visited(l, false);
        queue<pair<int, int> > q;

        //设置通用字符串哈希表,对每个字符串截取一个字符构成一个新的字符串作为hashkey
        for (int i = 0;i < wordList.size();i++) {
            for (int j = 0;j < wordList[i].length();j++) {
                //必须加上分隔符，防止错位
                string ns = wordList[i].substr(0, j) + "*" + wordList[i].substr(j + 1);
                _map[ns].push_back(i);
            }
        }

        //寻找相连的字符串
        vector<vector<int> > connect;
        connect.resize(l, {});
        for (int i = 0;i < wordList.size();i++) {
            for (int j = 0;j < wordList[i].length();j++) {
                string ns = wordList[i].substr(0, j) + "*" + wordList[i].substr(j + 1);
                for (int k : _map[ns]) {
                    if (k != i)
                        connect[i].push_back(k);
                }
            }
        }


        q.push({l - 1, 1});
        visited[l - 1] = true;
        //将开始字符串加入搜索队列
        //first为字符编号，second为转换队列的长度
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if (wordList[p.first] == endWord)
                return p.second;
            for (int i : connect[p.first]) {
                if (!visited[i]) {
                    q.push({i, p.second + 1});
                    visited[i] = true;
                }
            }
        }

        return 0;      
    }
};
