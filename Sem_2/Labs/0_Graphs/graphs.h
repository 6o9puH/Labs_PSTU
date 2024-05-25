#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <unordered_map>
#include <unordered_set>
#include "ui_graphs.h"

using namespace std;

struct Edge;

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
    void DepthBypass(int startData, vector<int>& dbp);
    void WidthBypass(int startData, vector<int>& wbp);
    vector<int> AlgorithmBypass(int startData, int endData);
};

class Graphs : public QMainWindow
{
    Q_OBJECT

public:
    Graphs(QWidget *parent = nullptr);
    ~Graphs();
    Graph graph;

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    Ui::Graphs *ui;
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
    void on_pushButton_9_clicked();
};
