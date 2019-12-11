알고리즘 스터디 with C++
--------------
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
## 그래프
  ### 그래프의 개념과 적용 사례
    * 그래프란
        * 단순히 노드(N, node)와 그 노드를 연결하는 간선(E, edge)을 하나로 모아 놓은 자료 구조
        * 즉, 연결되어 있는 객체 간의 관계를 표현할 수 있는 자료 구조이다.
        
    * 그래프 관련 용어
        * 정점(vertex): 위치라는 개념. (node 라고도 부름)
        * 간선(edge): 위치 간의 관계. 즉, 노드를 연결하는 선 (link, branch 라고도 부름)
        * 인접 정점(adjacent vertex): 간선에 의 해 직접 연결된 정점
        * 정점의 차수(degree): 무방향 그래프에서 하나의 정점에 인접한 정점의 수
          * 무방향 그래프에 존재하는 정점의 모든 차수의 합 = 그래프의 간선 수의 2배
        * 진입 차수(in-degree): 방향 그래프에서 외부에서 오는 간선의 수 (내차수 라고도 부름)
        * 진출 차수(out-degree): 방향 그래픙에서 외부로 향하는 간선의 수 (외차수 라고도 부름)
          * 방향 그래프에 있는 정점의 진입 차수 또는 진출 차수의 합 = 방향 그래프의 간선의 수(내차수 + 외차수)
        * 경로 길이(path length): 경로를 구성하는 데 사용된 간선의 수
        * 단순 경로(simple path): 경로 중에서 반복되는 정점이 없는 경우
        * 사이클(cycle): 단순 경로의 시작 정점과 종료 정점이 동일한 경우

    * 그래프 특징
        * 네트워크 형 구조
            * 지도
            * 지하철 노선도의 최단 경로 
            * 전기 회로의 소자들
            * 도로(교차점과 일방 통행길) 
            * 선수 과목 등
        * 그래프는 여러 개의 고립된 부분 그래프(Isolated Subgraphs)로 구성될 수 있다.
        * 탐색 방법
            1. 깊이 우선 탐색(DFS, Depth-First Search)
            2. 너비 우선 탐색(BFS, Breadth-First Search)
           
    * 그래프 구현 방법
        1. 인접 리스트(Adjacency List)
            * 가장 '일반적인 방법'
            * 모든 정점(혹은 노드)을 인접 리스트에 저장한다. 즉, 각각의 정점에 인접한 정점들을 리스트로 표시한 것이다.
            * 배열(혹은 해시테이블)과 배열의 각 인덱스마다 존재하는 또 다른 리스트(배열, 동적 가변 크기 배열(ArrayList), 연결리스트(LinkedList) 등)를 이용해서 인접 리스트를 표현
            * 사용하는 경우
                * 그래프 내에 적은 숫자의 간선만을 가지는 '희소 그래프(Sparse Graph)' 의 경우
                * 어떤 노드에 '인접한 노드'들을 찾는 경우
                * 그래프에 존재하는 '모든 간선의 수'를 찾는 경우: O(N+E)
        2. 인접 행렬(Adjacency Matrix)
            * 인접 행렬은 NxN 불린 행렬(Boolean Matrix)
            * matrix[i][j]가 true라면 i -> j로의 간선이 있다는 뜻이다.
            * 사용하는 경우
                * 그래프에 간선이 많이 존재하는 '밀집 그래프(Dense Graph)' 의 경우
                * 두 정점을 연결하는 '간선의 존재 여부'를 판단하는 경우 : O(1) ((M[i][j]이므로)
                * '정점의 차수'를 구하는 경우: O(N)

  ### 트리나 그래프를 방문 또는 탐색하는 방법 1: BFS(너비 우선 탐색)
    * BFS(Breadth First Search)란
        * 너비 우선 탐색
        * 루트 노드(혹은 다른 임의의 노드)에서 시작해서 인접한 노드를 먼저 탐색하는 방법
        * 깊이가 1인 모든 정점을 방문하고 나서 그 다음에는 깊이가 2인 모든 정점을, 그 다음에는 깊이가 3인 모든 정점을 방문하는 식으로 계속 방문하다가 더 이상 방문할 곳이 없으면 탐색을 마친다.
        
    * BFS 특징
        * 선입선출(FIFO) 원칙
        * 시간 복잡도: O(V+E) (단, 인접 리스트로 구현된 그래프인 경우)
            * V: 정점의 개수
            * E: 간선의 개수
        * 임의의 정점을 처음 방문할 때 시작점으로부터의 '최단 거리'를 알 수 있다.
        * 'Prim', 'Dijkstra' 알고리즘과 유사하다.
        * 너비 우선 탐색(BFS)이 깊이 우선 탐색(DFS)보다 좀 더 복잡하다.
        
    * BFS 사용 예시
        * 두 노드 사이의 최단 '경로 탐색'
        * 혹은 두 노드 사이의 임의의 '경로 탐색'
        * 트리의 지름 구하기
        
    * BFS 구현 방법
        * 선입선출(FIFO) 원칙으로 탐색하기 위해 큐(Queue)를 이용
            * 탐색한 정점 순으로 인접 정점을 찾는다.
            * 즉, 방문한 정점의 위치를 기억하기 위해 큐(Queue)를 이용
        
    * BFS 알고리즘 과정
        1. 시작 노드를 큐(Queue)에 배정한다.
        2. 큐(Queue)가 빌 떄까지 아래의 과정을 반복한다.
        3. 큐(Queue)의 가장 앞에 있는 노드를 pop
        4. 현재 노드에 인접한 모든 노드들 중 아직 방문하지 않은 노드들을 큐(Queue)에 push
        

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
