Comparing the performance of **static**, **incremental**, and **dynamic**
PageRank ([pull], [CSR]).

This experiment was for comparing the performance between the three modes of
PageRank computation: **static**, **incremental**, and **dynamic**.
Teleport-based dead end handling strategy was used here, since it is the one
that is most commonly used with the PageRank algorithm. With a random surfer
model, this means the surfer always jumps to a random vertex on the graph upon
reaching a dead end (a vertex with no outgoing edges, also called dangling
nodes). This experiment was done on *temporal graphs* for *insertions* and
*deletions*, with *L1*, *L2*, and *L∞-norm* as the error measurement function
for convergence check.

The PageRank algorithm used here is the *standard power-iteration (pull)* based
PageRank. The rank of a vertex in an iteration is calculated as `c₀ + αΣrₙ/dₙ`,
where `c₀` is the *common* *teleport contribution*, `α` is the *damping factor*,
`rₙ` is the *previous rank of vertex* with an incoming edge, `dₙ` is the
*out-degree* of the incoming-edge vertex, and `N` is the *total number of
vertices* in the graph. The *common teleport contribution* `c₀`, calculated as
`(1-α)/N + αΣrₙ/N` , which includes the *contribution due to a teleport from*
*any vertex* in the graph due to the damping factor `(1-α)/N`, and *teleport
from dangling vertices* (with *no outgoing edges*) in the graph `αΣrₙ/N`. This
is because, as mentioned before, a random surfer jumps to a random page upon
visiting a page with *no links*, in order to avoid the *rank-sink* effect. A
*damping factor* of `α = 0.85`, and a *tolerance* of  `τ = 10⁻⁶` was used.

From the results for all batch sizes, the **GM-RATIO** and **AM-RATIO** (for
**insertions (i)** and **deletions (d)**) between *static*, *incremental*, and
*dynamic* PageRank is shown in below table. These are relative time taken for
PageRank computation for each mode, with respect to the static mode using the
same error measurement function (i.e., separately for *L1*, *L2*, and
*Li-norm*). **Incremental** and **dynamic** PageRank almost always perform
better than the **static** mode (for *insertions* as well as *deletions*),
except when using **L1-norm** as convergence check (where they perform better
upto a batch size of `1E+6`).

<br>

**Table 1: Relative time for all batch sizes**

| BATCH: all   | L1-sta | L1-inc | L1-dyn | L2-sta | L2-inc | L2-dyn | Li-sta | Li-inc | Li-dyn |
| ------------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| GM-RATIO (i) | 1.00   | 0.67   | 0.61   | 1.00   | 0.55   | 0.47   | 1.00   | 0.45   | 0.39   |
| GM-RATIO (d) | 1.00   | 0.67   | 0.62   | 1.00   | 0.54   | 0.47   | 1.00   | 0.47   | 0.42   |
| AM-RATIO (i) | 1.00   | 0.78   | 0.73   | 1.00   | 0.70   | 0.63   | 1.00   | 0.56   | 0.50   |
| AM-RATIO (d) | 1.00   | 0.72   | 0.71   | 1.00   | 0.67   | 0.61   | 1.00   | 0.55   | 0.51   |

<br>

**Table 2: Relative speedup for all batch sizes**

| BATCH: all   | L1-sta | L1-inc | L1-dyn | L2-sta | L2-inc | L2-dyn | Li-sta | Li-inc | Li-dyn |
| ------------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| GM-RATIO (i) | 1.00   | 1.49   | 1.65   | 1.00   | 1.80   | 2.12   | 1.00   | 2.20   | 2.54   |
| GM-RATIO (d) | 1.00   | 1.50   | 1.62   | 1.00   | 1.84   | 2.14   | 1.00   | 2.12   | 2.40   |
| AM-RATIO (i) | 1.00   | 1.28   | 1.37   | 1.00   | 1.44   | 1.58   | 1.00   | 1.77   | 2.01   |
| AM-RATIO (d) | 1.00   | 1.38   | 1.41   | 1.00   | 1.49   | 1.63   | 1.00   | 1.82   | 1.95   |

<br>
<br>

With a specific batch size of 10^3, the **GM-RATIO** and **AM-RATIO** (for
**insertions (i)** and **deletions (d)**) between *static*, *incremental*, and
*dynamic* PageRank is shown in below table. This is shown as it can be a good
choice of batch size for dynamic update.

**Incremental** and **dynamic** PageRank almost always perform
better than the **static** mode (for *insertions* as well as *deletions*),
except when using **L1-norm** as convergence check (where they perform better
upto a batch size of `1E+6`).


**1.00:0.75:0.58** for insertions, and **1.00:0.81:0.63** for deletions. For a
batch size of *1E+3*, the *GM-RATIO* is *1.00:0.65:0.52* for insertions, and
*1.00:0.69:0.55* for deletions. With respect to *GM-RATIO*, **incremental**
PageRank is observed to perform better than the *static* mode upto a batch size
of `1E+4` for insertions and deletions, while **dynamic** PageRank performs
better than the static mode upto a batch size of `5E+5` for insertions and
`1E+5` for deletions. Similarly, the **AM-RATIO** for insertions is
**1.00:0.84:0.75**, and for deletions is **1.00:0.94:0.84**. For a batch size of
*1E+3*, the *AM-RATIO* is *1.00:0.25:0.21* for insertions, and *1.00:0.29:0.25*
for deletions. With respect to *AM-RATIO*, **incremental** PageRank is observed
to perform better than the *static* mode upto a batch size of `1E+6` for
insertions and `5E+5` for deletions, while **dynamic** PageRank always
outperforms the static mode for insertions but only upto a batch size of `1E+6`
for deletions.

When using **L2-norm** for convergence check, the **GM-RATIO** between *static*,
*incremental*, and *dynamic* PageRank is **1.00:0.58:0.46** for insertions, and
**1.00:0.60:0.48** for deletions. For a batch size of *1E+3*, the *GM-RATIO* is
*1.00:0.50:0.40* for insertions, and *1.00:0.47:0.38* for deletions. With
respect to *GM-RATIO*, **incremental** PageRank is observed to perform better
than the *static* mode upto a batch size of `1E+6` for insertions and `5E+5` for
deletions, while **dynamic** PageRank always outperforms the static mode for
insertions but only upto a batch size of `1E+6` for deletions. Similarly, the
**AM-RATIO** for insertions is **1.00:0.72:0.63**, and for deletions is
**1.00:0.73:0.65**. For a batch size of *1E+3*, the *AM-RATIO* is
*1.00:0.18:0.15* for insertions, and *1.00:0.12:0.09* for deletions. With
respect to *AM-RATIO*, **incremental** PageRank always outperforms the static
mode for insertions but only upto a batch size of `1E+6` for deletions, while
**dynamic** PageRank always outperforms the static mode for insertions as well
as deletions.

When using **L∞-norm** for convergence check, the **GM-RATIO** between *static*,
*incremental*, and *dynamic* PageRank is **1.00:0.48:0.39** for insertions, and
**1.00:0.49:0.40** for deletions. For a batch size of *1E+3*, the *GM-RATIO* is
*1.00:0.49:0.40* for insertions, and *1.00:0.44:0.35* for deletions. With
respect to *GM-RATIO*, **incremental** and **dynamic** PageRank always
outperform the static mode for insertions as well as deletions. Similarly, the
**AM-RATIO** for insertions is **1.00:0.50:0.45**, and for deletions is
**1.00:0.50:0.46**. For a batch size of *1E+3*, the *AM-RATIO* is
*1.00:0.17:0.14* for insertions, and *1.00:0.11:0.09* for deletions. With
respect to *AM-RATIO*, **incremental** and **dynamic** PageRank again always
outperform the static mode for both insertions and deletions.




| BATCH: 10³   | L1-sta | L1-inc | L1-dyn | L2-sta | L2-inc | L2-dyn | Li-sta | Li-inc | Li-dyn |
| ------------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| GM-RATIO (i) | 1.00   | 0.59   | 0.56   | 1.00   | 0.48   | 0.43   | 1.00   | 0.41   | 0.37   |
| GM-RATIO (d) | 1.00   | 0.58   | 0.56   | 1.00   | 0.43   | 0.38   | 1.00   | 0.40   | 0.36   |
| AM-RATIO (i) | 1.00   | 0.22   | 0.28   | 1.00   | 0.16   | 0.15   | 1.00   | 0.16   | 0.15   |
| AM-RATIO (d) | 1.00   | 0.23   | 0.30   | 1.00   | 0.15   | 0.13   | 1.00   | 0.16   | 0.15   |


From the results it can be said that performance improvement provided by
**incremental**/**dynamic** PageRank computation is higher when using
**L∞-norm** for convergence check, when compared to **L2-norm** or **L1-norm**.
However, what can be said about **incremental** vs **dynamic** PageRank? When
does **incremental**/**dynamic** PageRank stop being better than the **static**
mode? How can this be explained? It should be noted that **L∞-norm** itself
converges much faster than **L2-norm** or **L1-norm**.

All outputs are saved in [out](out/) and a small part of the output is listed
here. Some [charts] are also included below, generated from [sheets]. The input
data used for this experiment is available at ["graphs"] (for small ones), and
the [SuiteSparse Matrix Collection]. This experiment was done with guidance
from [Prof. Dip Sankar Banerjee] and [Prof. Kishore Kothapalli].

<br>

```bash
$ g++ -std=c++17 -O3 main.cxx
$ ./a.out ~/data/CollegeMsg.txt
$ ./a.out ~/data/email-Eu-core-temporal.txt
$ ...

# ...
#
# Using graph /home/subhajit/data/sx-stackoverflow.txt ...
# Temporal edges: 63497051
#
# # Batch size 1e+01
# order: 747591 size: 5768470 {} [01780.516 ms; 083 iters.] [0.0000e+00 err.] I:pagerankMonolithicSeqL1Norm (static)
# order: 747591 size: 5768470 {} [00061.906 ms; 002 iters.] [3.4813e-06 err.] I:pagerankMonolithicSeqL1Norm (incremental)
# order: 747591 size: 5768470 {} [01290.480 ms; 065 iters.] [8.5782e-04 err.] I:pagerankMonolithicSeqL1Norm (dynamic)
# order: 747591 size: 5768470 {} [00663.592 ms; 031 iters.] [7.5746e-04 err.] I:pagerankMonolithicSeqL2Norm (static)
# order: 747591 size: 5768470 {} [00025.209 ms; 001 iters.] [3.2860e-06 err.] I:pagerankMonolithicSeqL2Norm (incremental)
# order: 747591 size: 5768470 {} [00022.098 ms; 001 iters.] [2.5521e-05 err.] I:pagerankMonolithicSeqL2Norm (dynamic)
# order: 747591 size: 5768470 {} [00493.795 ms; 023 iters.] [2.5442e-03 err.] I:pagerankMonolithicSeqLiNorm (static)
# order: 747591 size: 5768470 {} [00025.201 ms; 001 iters.] [3.2860e-06 err.] I:pagerankMonolithicSeqLiNorm (incremental)
# order: 747591 size: 5768470 {} [00022.266 ms; 001 iters.] [2.5521e-05 err.] I:pagerankMonolithicSeqLiNorm (dynamic)
# order: 747590 size: 5768462 {} [01837.787 ms; 086 iters.] [0.0000e+00 err.] D:pagerankMonolithicSeqL1Norm (static)
# order: 747590 size: 5768462 {} [00025.104 ms; 001 iters.] [8.4602e-07 err.] D:pagerankMonolithicSeqL1Norm (incremental)
# order: 747590 size: 5768462 {} [01228.030 ms; 064 iters.] [8.6126e-04 err.] D:pagerankMonolithicSeqL1Norm (dynamic)
# order: 747590 size: 5768462 {} [00663.882 ms; 031 iters.] [7.5723e-04 err.] D:pagerankMonolithicSeqL2Norm (static)
# order: 747590 size: 5768462 {} [00025.110 ms; 001 iters.] [8.4602e-07 err.] D:pagerankMonolithicSeqL2Norm (incremental)
# order: 747590 size: 5768462 {} [00022.135 ms; 001 iters.] [2.5853e-05 err.] D:pagerankMonolithicSeqL2Norm (dynamic)
# order: 747590 size: 5768462 {} [00493.128 ms; 023 iters.] [2.5432e-03 err.] D:pagerankMonolithicSeqLiNorm (static)
# order: 747590 size: 5768462 {} [00025.105 ms; 001 iters.] [8.4602e-07 err.] D:pagerankMonolithicSeqLiNorm (incremental)
# order: 747590 size: 5768462 {} [00022.171 ms; 001 iters.] [2.5853e-05 err.] D:pagerankMonolithicSeqLiNorm (dynamic)
# order: 1652959 size: 11582276 {} [02910.828 ms; 058 iters.] [0.0000e+00 err.] I:pagerankMonolithicSeqL1Norm (static)
# ...
```

[![](https://i.imgur.com/mYXI0j9.png)][sheetp]
[![](https://i.imgur.com/YwyNmUC.png)][sheetp]
[![](https://i.imgur.com/OJudGO9.png)][sheetp]
[![](https://i.imgur.com/ctGz13u.png)][sheetp]

[![](https://i.imgur.com/ghxTMZm.png)][sheetp]
[![](https://i.imgur.com/2b43USf.png)][sheetp]
[![](https://i.imgur.com/XtrIaXx.png)][sheetp]
[![](https://i.imgur.com/NXqMvvc.png)][sheetp]

[![](https://i.imgur.com/tI2P5nx.gif)][sheetp]
[![](https://i.imgur.com/WQESw4R.gif)][sheetp]
[![](https://i.imgur.com/TIpC1WP.gif)][sheetp]
[![](https://i.imgur.com/oREOIU4.gif)][sheetp]

[![](https://i.imgur.com/oU0SPpw.gif)][sheetp]
[![](https://i.imgur.com/zdoJuSC.gif)][sheetp]
[![](https://i.imgur.com/uInXlFX.gif)][sheetp]
[![](https://i.imgur.com/gNWz0VB.gif)][sheetp]

<br>
<br>


## References

- [How to check for Page Rank convergence?][L∞ norm]
- [L0 Norm, L1 Norm, L2 Norm & L-Infinity Norm](https://montjoile.medium.com/l0-norm-l1-norm-l2-norm-l-infinity-norm-7a7d18a4f40c)
- [PageRank Algorithm, Mining massive Datasets (CS246), Stanford University](https://www.youtube.com/watch?v=ke9g8hB0MEo)
- [Weighted Geometric Mean Selected for SPECviewperf® Composite Numbers](https://www.spec.org/gwpg/gpc.static/geometric.html)
- [SuiteSparse Matrix Collection]

<br>
<br>

[![](https://i.imgur.com/BnCiig7.jpg)](https://www.youtube.com/watch?v=04Uv44DRJAU)

[Prof. Dip Sankar Banerjee]: https://sites.google.com/site/dipsankarban/
[Prof. Kishore Kothapalli]: https://cstar.iiit.ac.in/~kkishore/
[SuiteSparse Matrix Collection]: https://suitesparse-collection-website.herokuapp.com
["graphs"]: https://github.com/puzzlef/graphs
[nvGraph]: https://github.com/rapidsai/nvgraph
[pull]: https://github.com/puzzlef/pagerank-push-vs-pull
[CSR]: https://github.com/puzzlef/pagerank-class-vs-csr
[L1 norm]: https://github.com/rapidsai/nvgraph/blob/main/cpp/src/pagerank.cu#L154
[L2 norm]: https://github.com/rapidsai/nvgraph/blob/main/cpp/src/pagerank.cu#L149
[L∞ norm]: https://stackoverflow.com/a/29321153/1413259
[charts]: https://photos.app.goo.gl/zHuZHbwYjgcSpgWZ8
[sheets]: https://docs.google.com/spreadsheets/d/19ndHM7f9EeiqZ9F_b2EXqKlw_KilPdbU1Essz-in5dY/edit?usp=sharing
[sheetp]: https://docs.google.com/spreadsheets/d/e/2PACX-1vQgNZ-ITRO_eCShKmFn06yT6xiDafLCHeKO_OeByBxCJ6O6g_5MQb8hhrmXsKrTq2gznh0QLdl_i1Mj/pubhtml
