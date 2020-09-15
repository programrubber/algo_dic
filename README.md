알고리즘 스터디 with C++
--------------
  [백준 스터디 링크]
  [백준 브루트 포스 문제]

## C++
  * [C++ STL 정리]

## 기본 알고리즘
  - [최대공약수, 최소공배수]

## 트리
  ### [이진 트리 순회]
   * 전위 순회 (Pre-order, PLR), 순서: 루트, 왼쪽 자식, 오른쪽 자식
   * 중위 순회 (In-order, LPR)   순서: 왼쪽 자식, 루트, 오른쪽 자식
   * 후위 순회 (Post-order, LRP) 순서: 왼쪽 자식, 오른쪽 자식, 루트
   * [1991.cpp] ([트리 순회], 백준 1991)
     * 주어진 Tree의 전위, 중위, 후위 순회 탐색
   * [2263.cpp] ([트리의 순회], 백준 2263)
     * 중위, 후위를 이용하여 전위를 구하는 문제
     * 후위의 마지막 값이 parent 값이며, parent값을 중위에서 찾아 L, R의 범위를 찾는 것을 반복
     ```cpp
        void preOrder() {
          cout<<parent
          preOrder(left)
          preOrder(right)
        }
        void inOrder() {
          preOrder(left)
          cout<<parent
          preOrder(right)
        }
        void postOrder() {
          preOrder(left)
          preOrder(right)
          cout<<parent
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
  * 최적화문제의 최적해를 구하기 위해 모든 후보해들을 조사
    - 결정문제 또는 경우의 수 문제등에 적용
    - 모든 후보해들을 조사하기 위해 후보해들을 생성
    - 후보해들은 "순열, 조합, 부분집합"과 연관
    - 모든 가능성을 따져야 하므로 문제의 N이 커질수록 실행시간이 지수승으로 상승함
  * 전통적인 조합 최적화 문제
    - 최단 경로(Shortest path) 문제
    - TSP(Traveling Salesman person) 문제
    - 배낭(Kanpsack) 문제
  * 구현
    - 반복적 구조: 중첩된 반복문
    - 재귀적 구조: 재귀 호출을 통한 구현
  ### 부분집합
   * 비트 연산을 통해 부분집합을 생성 [ex) {A,B,C} 부분 집합 표현 방법]
     - {},      2진수: 000, 10진수: 0
     - {C},     2진수: 001, 10진수: 1
     - {B},     2진수: 010, 10진수: 2
     - {B,C},   2진수: 011, 10진수: 3
     - {A},     2진수: 100, 10진수: 4
     - {A,C},   2진수: 101, 10진수: 5
     - {A,B},   2진수: 110, 10진수: 6
     - {A,B,C}, 2진수: 111, 10진수: 7
    *0~(2^n -1)로 부분 집합을 생성
   * [subset.cpp] ([부분집합 로직])
   * [2039_subset.cpp] ([일곱 난쟁이], 백준 2039)
   ```cpp
    int bits[SIZE];

    void subset (int start, int end) {
      if (start == end) {
        for (int i=0; i<end; i++) {
          if (bits[i]) {
            // print
          }
        }
        return
      }
      bits[i]=0; subset(start+1, end);
      bits[i]=1; subset(start+1, end);
    }
   ```
  ### 순열
   * [perm.cpp]([순열], 요소들을 순서대로 선택)
   * [perm_change.cpp]([순열], 두 요소의 교환으로 생성되는 순열)
   * [10972.cpp] ([다음 순열], 백준 10972, non-pass)
   ```cpp
    vector <int> vec;
    int N;

    int perm(int start, int end) {
        if (start == end) {
            for (int i = 0; i < N; i++) {
                cout << vec.at(i) << " ";
            }
            cout << endl;
        }
        for (int i = start; i < end; i++) {
            swap(vec[start], vec[i]);
            perm(start+1, end);
            swap(vec[start], vec[i]);
        }
    }
    perm(0,N);
   ```
 ### 조합 (Combination)
   * 서로 다른 n개의 원소에서 순서에 상관없이 r개를 뽑을때, n개에서 r개를 택하는 조합
   * ex) aaaabb를 일렬로 나열하는 방법은? 20가지 (5C3) -> 순열로 생각하고 같은것들의 순서를 제거하면 됨
   * ex) (1,2,3,4,5)중 3개를 선택하는 방법은?
     (1,2,3), (1,2,4), (1,2,5), (1,3,4), (1,3,5), (1,4,5), (2,3,4), (2,3,5), (2,4,5), (3,4,5) 총 10가지
   * [2309_combination.cpp] ([일곱 난쟁이], 백준 2039) 
   ```cpp
    #include <iostream>
    using namespace std;

    int N, K; // N: 집합 원소의 갯수, K: 선택할 원소의 갯수
    int arr[6];
    int choise[6];
    int cnt;

    void comb(int number, int idx) {
        if (idx > K) {
            for (int i=1; i<=K; i++) {
                cout << choise[i];
            }
            cout << endl;
            return;
        }
        if (number > N) {
            return;
        }
        choise[idx] = arr[number];
        comb(number+1, idx+1);
        comb(number+1, idx);
        // 중복 조합
        // comb(number, idx+1);
        // comb(number+1, idx);
    }

    int main() {
        cin >> N >> K;
        for (int i=1; i<= N; i++) {
            cin >> arr[i];
        }
        comb(1, 1);
    }
   ```

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
[2309_combination.cpp]: https://github.com/programrubber/algo_dic/blob/master/src/2039_combination.cpp

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
[C++ STL 정리]: https://github.com/programrubber/algo_dic/blob/master/doc/200804_cpp_stl.md

[(참고)]: https://github.com/WeareSoft/algorithm-study/blob/master/contents/180715.md
[백준 스터디 링크]: https://www.acmicpc.net/workbook/top
[백준 브루트 포스 문제]: https://www.acmicpc.net/step/22
