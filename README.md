알고리즘 스터디 with C++
--------------
##  기본 알고리즘
  - [최대공약수, 최소공배수]
## 트리
  ### [이진 트리 순회]
   * 전위 순회 (Pre-order, PLR)
   * 중위 순회 (In-order, LPR)
   * 후위 순회 (Post-order, LRP)
   * [1991.cpp] ([트리 순회], 백준 1991)
     * 주어진 Tree의 전위, 중위, 후위 순회 탐색
   * [2263.cpp] ([트리의 순회], 백준 2263)
     * 중위, 후위를 이용하여 전위를 구하는 문제
     * 후위의 마지막 값이 parent 값이며, parent값을 중위에서 찾아 L, R의 범위를 찾는 것을 반복
     ```cpp
        void preOrder() {
          cout<<node
          preOrder()
          preOrder()
        }
        void inOrder() {
          preOrder()
          cout<<node
          preOrder()
        }
        void postOrder() {
          preOrder()
          preOrder()
          cout<<node
        }
     ```
## 그래프 [(참고)]
  ### BFS, 너비 우선 탐색
   * [bfs.cpp] ([BFS 기본 로직])
   * [2667_bfs.cpp] ([단지 번호 붙이기], 백준 2667)
   * [2178_bfs.cpp] ([미로 탐색], 백준 2178)
   * [2146_bfs_dfs.cpp] ([다리 만들기], 백준 2146)
  ### DFS, 깊이 우선 
   * [dfs.cpp] ([DFS 기본 로직])
## 완전 탐색
  ### 부분집합
   * [subset.cpp] ([부분집합 로직])
   * [2039_subset.cpp] ([일곱 난쟁이], 백준 2039)
  ### 순열
   * [perm.cpp]([순열], 요소들을 순서대로 선택)
   * [perm_change.cpp]([순열], 두 요소의 교환으로 생성되는 순열)
   * [10972.cpp] ([다음 순열], 백준 10972, non-pass)

[bfs.cpp]: https://github.com/programrubber/algo_dic/blob/master/algo/bfs.cpp
[dfs.cpp]: https://github.com/programrubber/algo_dic/blob/master/algo/dfs.cpp
[subset.cpp]: https://github.com/programrubber/algo_dic/blob/master/algo/subset.cpp
[perm.cpp]: https://github.com/programrubber/algo_dic/blob/master/algo/perm.cpp
[perm_change.cpp]: https://github.com/programrubber/algo_dic/blob/master/algo/perm_change.cpp

[2667_bfs.cpp]: https://github.com/programrubber/algo_dic/blob/master/src/2667_bfs.cpp
[2178_bfs.cpp]: https://github.com/programrubber/algo_dic/blob/master/src/2178_bfs.cpp
[2146_bfs_dfs.cpp]: https://github.com/programrubber/algo_dic/blob/master/src/2146_bfs_dfs.cpp
[2039_subset.cpp]: https://github.com/programrubber/algo_dic/blob/master/src/2039_subset.cpp
[10972.cpp]: https://github.com/programrubber/algo_dic/blob/master/src/10972.cpp
[2263.cpp]: https://github.com/programrubber/algo_dic/blob/master/src/2263.cpp
[1991.cpp]: https://github.com/programrubber/algo_dic/blob/master/src/1991.cpp

[BFS 기본 로직]: http://www.algocoding.net/graph/traversal/BFS.html
[단지 번호 붙이기]: https://www.acmicpc.net/problem/2667
[미로 탐색]: https://www.acmicpc.net/problem/2178
[DFS 기본 로직]: http://www.algocoding.net/graph/traversal/DFS.html
[다리 만들기]: https://www.acmicpc.net/problem/2146
[부분집합 로직]: http://www.algocoding.net/design/search/subset.html
[일곱 난쟁이]: https://www.acmicpc.net/problem/2309
[트리의 순회]: https://www.acmicpc.net/problem/2263
[순열]: http://www.algocoding.net/design/search/permutation.html
[다음 순열]: https://www.acmicpc.net/problem/10972
[이진 트리 순회]: http://www.algocoding.net/tree/tree_traversal.html
[트리 순회]: https://www.acmicpc.net/problem/1991

[최대공약수, 최소공배수]: https://github.com/programrubber/algo_dic/blob/master/doc/200804_gcd_lcm.md

[(참고)]: https://github.com/WeareSoft/algorithm-study/blob/master/contents/180715.md
