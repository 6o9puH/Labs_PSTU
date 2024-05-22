#pragma once
#include <QMainWindow>
#include "ui_tsp.h"
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Edge;

struct Node
{
    int data;
    vector<Edge*> edges;
    QPoint pos;
    Node() { pos = QPoint(350, 250); }
};

struct Edge
{
    int weight;
    Node* to;
    Node* from;
};

struct Graph
{
    vector<Node*> vnodes;

    unordered_map<int, Node*> nodes;

    void addNode(int data);
    void addEdge(int fromData, int toData, int weight);
    void clearGraph();
    void updateEdgeWeight(int startData, int endData, int newWeight);

    void removeNode(int data);
    void removeEdge(int startData, int endData);

    int** createNodeMap ();
    void min_line(int** map);
    void min_column(int** map);
    int min_str(int** map, int i, int l);
    int min_stl(int** map, int i, int l);
    Edge* clear_map(int** map);
    vector<int> TSPsolve();
    int way(vector<int> path);
};

class TSP : public QMainWindow
{
    Q_OBJECT

public:
    TSP(QWidget *parent = nullptr);
    ~TSP();
    Graph graph;

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    Ui::TSP *ui;
    Node* m_selectedNode;
    bool m_nodeSelected;

    bool sel = 0;
    Node* sNode;

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
};
