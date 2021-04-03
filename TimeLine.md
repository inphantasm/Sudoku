## 2021/04/03

- 基本内容
  - Sudoku类
    - 现在可以计算每个节点可能的数值，将用于填写数独功能
  - Sudoku_Gen类
    - 现在可以为数独终局挖掘可选数量的孔来产生一个有唯一解的数独

## 2021/04/02

- 基本内容
  - Sudoku类：
    - 将matrix原有数据结构更改为square(==vector\<vector\<char\>\>)
  - Sudoku_Gen类：
    - 目前打算生成一个填满的9*9数独终局来满足需求，暂时意义不明，考虑可能用数独终局挖空来产生一个数独。
    - GenFinal_Violent，暴力生成一个不满足九宫格要求的数独终局
    - GenFinal_Elegant，对已有的一个数独终局(Starting.ini)作行列变换来使其成为另一个数独终局
      - 及其附属行列变换函数swap_row、swap_col、swap_row_chunk、swap_col_chunk

## 2021/04/01

- 建立项目
  - 根据需求建立了Sudoku、Sudoku_Generator和Sudoku_Solver。

- 基本内容
  - Sudoku类：
    - char matrix\[9]\[9]，用于存储数独
    - int blank，用于记录数独目前“空白”('#')的个数。