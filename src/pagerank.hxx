#pragma once
#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::move;




// PAGERANK-OPTIONS
// ----------------

template <class T>
struct PagerankOptions {
  int  repeat;
  int  toleranceNorm;
  T    damping;
  T    tolerance;
  int  maxIterations;

  PagerankOptions(int repeat=1, int toleranceNorm=1, T damping=0.85, T tolerance=1e-6, int maxIterations=500) :
  repeat(repeat), toleranceNorm(toleranceNorm), damping(damping), tolerance(tolerance), maxIterations(maxIterations) {}
};




// PAGERANK-RESULT
// ---------------

template <class T>
struct PagerankResult {
  vector<T> ranks;
  float iterations;
  float time;
  float load;

  PagerankResult(vector<T>&& ranks, float iterations=0, float time=0, float load=1) :
  ranks(ranks), iterations(iterations), time(time), load(load) {}

  PagerankResult(vector<T>& ranks, float iterations=0, float time=0, float load=1) :
  ranks(move(ranks)), iterations(iterations), time(time), load(load) {}


  // Get initial ranks (when no vertices affected for dynamic pagerank).
  template <class G>
  static PagerankResult<T> initial(const G& x, const vector<T>* q=nullptr) {
    int  N = x.order();
    auto a = q? *q : createContainer(x, T());
    if (!q) fillAt(a, T(1)/N, x.vertices());
    return {a, 0, 0};
  }
};




// PAGERANK-DATA
// -------------
// Using Pagerank Data for performance!

struct PagerankData {
  pair<vector<int>, int> dynamicInVertices;
  vector<int> sourceOffsets;
  vector<int> destinationIndices;
  vector<int> vertexData;
};

template <class G, class H>
auto dynamicInVerticesD(const G& x, const H& xt, const G& y, const H& yt, const PagerankData *D) {
  return D? D->dynamicInVertices : dynamicInVertices(x, xt, y, yt);
}

template <class G, class J>
auto sourceOffsetsD(const G& x, const J& ks, const PagerankData *D) {
  return D && !D->sourceOffsets.empty()? D->sourceOffsets : sourceOffsets(x, ks);
}

template <class G, class J>
auto destinationIndicesD(const G& x, const J& ks, const PagerankData *D) {
  return D && !D->destinationIndices.empty()? D->destinationIndices : destinationIndices(x, ks);
}

template <class G, class J>
auto vertexDataD(const G& x, const J& ks, const PagerankData *D) {
  return D && !D->destinationIndices.empty()? D->vertexData : vertexData(x, ks);
}
