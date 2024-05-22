#include "tsp.h"
#include "ui_tsp.h"
#include <cmath>
#include <QPainter>

void Graph::addNode(int data)
{
    if (nodes.find(data) == nodes.end())
    {
        Node* newNode = new Node;
        newNode->data = data;
        nodes[data] = newNode;
        vnodes.push_back(newNode);//
    }
}


void Graph::addEdge(int fromData, int toData, int weight)
{
    for (Edge* edge : nodes[fromData]->edges)
    {
        if (edge->to == nodes[toData])
        {
            return;
        }
    }

    Edge* newEdge = new Edge();
    newEdge->to = nodes[toData];
    newEdge->from = nodes[fromData];
    newEdge->weight = weight;
    nodes[fromData]->edges.push_back(newEdge);
}

void Graph::clearGraph()
{
    for (auto& pair : nodes)
    {
        Node* node = pair.second;
        delete node;
    }
    nodes.clear();
    vnodes.clear();
}

void Graph::updateEdgeWeight(int startData, int endData, int newWeight)
{
    if (nodes.find(startData) == nodes.end() || nodes.find(endData) == nodes.end())
    {
        return;
    }

    Node* startNode = nodes[startData];
    Node* endNode = nodes[endData];

    for (Edge* edge : startNode->edges)
    {
        if (edge->to == endNode)
        {
            edge->weight = newWeight;
            return;
        }
    }
}

void Graph::removeNode(int data)
{
    for (auto& pair : nodes)
    {
        Node* node = pair.second;
        vector<Edge*> edges_to_remove;

        for (Edge* edge : node->edges)
        {
            if (edge->to->data == data)
            {
                edges_to_remove.push_back(edge);
            }
        }

        for (Edge* edge : edges_to_remove)
        {
            auto it = find(node->edges.begin(), node->edges.end(), edge);
            if (it != node->edges.end())
            {
                node->edges.erase(it);
                delete edge;
            }
        }
    }

    auto it = nodes.find(data);
    if (it != nodes.end())
    {
        delete it->second;
        nodes.erase(it);
    }

    Node* nodeToRemove = nullptr;//
    for (Node* nodeTo : vnodes)
    {
        if (nodeTo->data == data)
        {
            nodeToRemove = nodeTo;
            break;
        }
    }

    if (nodeToRemove)
    {

        auto itn = find(vnodes.begin(), vnodes.end(), nodeToRemove);
        if (itn != vnodes.end())
        {
            vnodes.erase(itn);
        }
    }
}

void Graph::removeEdge(int startData, int endData)
{
    auto startNodeIt = nodes.find(startData);
    auto endNodeIt = nodes.find(endData);

    if (startNodeIt == nodes.end() || endNodeIt == nodes.end())
    {
        return;
    }

    Node* startNode = startNodeIt->second;
    Node* endNode = endNodeIt->second;

    Edge* edgeToRemove = nullptr;

    for (Edge* edge : startNode->edges)
    {
        if (edge->to->data == endData)
        {
            edgeToRemove = edge;
            break;
        }
    }

    if (edgeToRemove)
    {
        auto it = find(startNode->edges.begin(), startNode->edges.end(), edgeToRemove);
        if (it != startNode->edges.end())
        {
            startNode->edges.erase(it);
            delete edgeToRemove;
        }
    }
}

TSP::TSP(QWidget *parent): QMainWindow(parent), ui(new Ui::TSP)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &TSP::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &TSP::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &TSP::on_pushButton_3_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &TSP::on_pushButton_4_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &TSP::on_pushButton_5_clicked);

    connect(ui->pushButton_6, &QPushButton::clicked, this, &TSP::on_pushButton_6_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &TSP::on_pushButton_7_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &TSP::on_pushButton_8_clicked);
}

TSP::~TSP()
{
    delete ui;
}

void TSP::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QFont font = painter.font();
    font.setPointSize(16);
    painter.setFont(font);
    for (const auto& pair : graph.nodes)
    {
        Node* node = pair.second;
        for (Edge* edge : node->edges)
        {
            QPoint pos_f;
            QPoint pos_t;
            int d = 20 * sin(atan(1));
            double angles = atan2(-(edge->to->pos.y() - node->pos.y()), (edge->to->pos.x() - node->pos.x()));
            pos_f = QPoint(node->pos.x() + 20 * cos(angles), node->pos.y() - 20 * sin(angles));
            pos_t = QPoint(edge->to->pos.x() - 20 * cos(angles), edge->to->pos.y() + 20 * sin(angles));
            painter.drawLine(pos_f, pos_t);
            int x_t = pos_f.x() + 4 * (pos_t.x() - pos_f.x()) / 5;
            int y_t = pos_f.y() - 4 * (pos_f.y() - pos_t.y()) / 5;
            painter.drawText(x_t - 10, y_t + 10, QString::number(edge->weight));

            QLine line(pos_f, pos_t);
            double angle = atan2(-line.dy(), line.dx()) - M_PI / 2;
            double arrowSize = 15;
            double arrowLength = 20;
            QPointF arrowP1 = pos_t + QPointF(sin(angle - M_PI / 10) * arrowSize, cos(angle - M_PI / 10) * arrowSize);
            QPointF arrowP2 = pos_t + QPointF(sin(angle + M_PI / 10) * arrowSize, cos(angle + M_PI / 10) * arrowSize);
            QPolygonF arrowHead;
            arrowHead << pos_t << arrowP1 << arrowP2;
            painter.drawPolygon(arrowHead);
        }
    }

    for (const auto& pair : graph.nodes)
    {
        Node* node = pair.second;
        painter.drawEllipse(node->pos, 20, 20);
        painter.drawText(node->pos.x() - 9, node->pos.y() + 8, QString::number(node->data));
    }
    if (sel)
    {
        painter.drawEllipse(100, 100, 40, 40);
        painter.setBrush(Qt::green);
        painter.drawEllipse(sNode->pos, 20, 20);
        painter.drawText(sNode->pos.x() - 9, sNode->pos.y() + 8, QString::number(sNode->data));
    }
}

void TSP::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_nodeSelected = false;
        for (const auto& pair : graph.nodes)
        {
            Node* node = pair.second;
            if ((event->pos() - node->pos).manhattanLength() < 30)
            {
                m_selectedNode = node;
                m_nodeSelected = true;
                break;
            }
        }
        update();
    }
}

void TSP::mouseMoveEvent(QMouseEvent* event)
{
    if (m_nodeSelected && m_selectedNode)
    {
        m_selectedNode->pos = event->pos();
        update();
    }
}
void TSP::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && m_nodeSelected)
    {
        m_nodeSelected = false;
        m_selectedNode = nullptr;
        update();
    }
}

int** Graph::createNodeMap ()//
{
    int** map = new int*[vnodes.size()];
        for (int i = 0; i < vnodes.size(); ++i)
        {
            map[i] = new int[vnodes.size()];
        }
    for (int i = 0; i < vnodes.size(); i++)
    {
        for (int j = 0; j < vnodes.size(); j++)
        {
            if (i != j)
            {
                bool f = false;
                for (Edge* e : vnodes[i]->edges)
                {
                    if (e->to == vnodes[j])
                    {
                        f = true;
                        map[i][j] = e->weight;
                        break;
                    }
                }
                if (f == false)
                {
                    map[i][j] = -1;
                }
            }
            else
            {
                map[i][j] = -1;
            }
        }
    }
    return map;
}

void Graph::min_line(int** map)
{
    int min;
    for (int i = 0; i < vnodes.size(); i++)
    {
        min = -1;
        for (int j = 0; j < vnodes.size(); j++)
        {
            if ((min > map[i][j] || min == -1) && map[i][j] >= 0)
            {
                min = map[i][j];
            }
        }
        for (int j = 0; j < vnodes.size(); j++)
        {
            if (map[i][j] != -1)
            {
                map[i][j] -= min;
            }
        }
    }
}

void Graph::min_column(int** map)
{
    int min;
    for (int i = 0; i < vnodes.size(); i++)
    {
        min = -1;
        for (int j = 0; j < vnodes.size(); j++)
        {
            if ((min > map[j][i] || min == -1) && map[j][i] >= 0)
            {
                min = map[j][i];
            }
        }
        for (int j = 0; j < vnodes.size(); j++)
        {
            if (map[j][i] != -1)
            {
                map[j][i] -= min;
            }
        }
    }
}

int Graph::min_str(int** map, int i, int l)
{
    int min = -1;
    for (int j = 0; j < vnodes.size(); j++)
    {
        if (j != l)
        {
            if ((min > map[i][j] || min == -1) && map[i][j] >= 0)
            {
                min = map[i][j];
            }
        }
    }
    if (min == -1)
    {
        min = 0;
    }

    return min;
}

int Graph::min_stl(int** map, int i, int l)
{
    int min = -1;
    for (int j = 0; j < vnodes.size(); j++)
    {
        if (j != l)
        {
            if ((min > map[j][i] || min == -1) && map[j][i] >= 0)
            {
                min = map[j][i];
            }
        }
    }
    if (min == -1)
    {
        min = 0;
    }

    return min;
}

Edge* Graph::clear_map(int** map)
{
    Edge* a = new Edge;
    int max = -1, k, m;
    for (int i = 0; i < vnodes.size(); i++)
    {
        for (int j = 0; j < vnodes.size(); j++)
        {
            if (map[i][j] == 0)
            {
                if (max <= min_str(map, i, j) + min_stl(map, j, i))
                {
                    max = min_str(map, i, j) + min_stl(map, j, i);
                    k = i;
                    m = j;
                }
            }
        }
    }

    if (max == -1)
    {
        return nullptr;
    }

    for (int i = 0; i < vnodes.size(); i++)
    {
        for (int j = 0; j < vnodes.size(); j++)
        {
            if (i == k)

            {
                map[i][j] = -1;
            }
            if (j == m)
            {
                map[i][j] = -1;
            }
        }
    }

    map[m][k] = -1;

    a->from = vnodes[k];
    a->to = vnodes[m];

    return a;
}

vector<int> Graph::TSPsolve()
{
    vector<Edge*> rez;
    vector<int> bestPath;
    int** map =createNodeMap();
    if (vnodes.size() == 2)
    {
        bestPath.push_back(vnodes[0]->data);
        bestPath.push_back(vnodes[1]->data);
        return bestPath;
    }

    int i = 0;
    while (i < vnodes.size())
    {
        min_line(map);
        min_column(map);
        rez.push_back(clear_map(map));
        i++;
    }

    for (Edge* e : rez)
    {
        if (e == nullptr)
        {
            bestPath.push_back(-1);
            return bestPath;
        }
    }

    bestPath.push_back(rez[0]->from->data);
    bestPath.push_back(rez[0]->to->data);
    for (int i = 2; i < vnodes.size(); i++)
    {
        for (int j = 1; j < rez.size(); j++)
        {
            if (rez[j]->from->data == bestPath[i - 1])
            {
                bestPath.push_back(rez[j]->to->data);
                break;
            }
        }
    }

    for (int i = 0; i < vnodes.size(); i++)
    {
        delete[] map[i];
    }
    delete[] map;

    return bestPath;
}

int Graph::way(vector<int> path)
{
    int w = 0;
    for (int i = 0; i < path.size() - 1; i++)
    {
        for (Node* n : vnodes)
        {
            if (n->data == path[i])
            {
                for (Node* nod : vnodes)
                {
                    if (nod->data == path[i + 1])
                    {
                        for (Edge* e : n->edges)
                        {
                            if (e->to == nod)
                            {
                                w += e->weight;
                            }
                        }
                    }
                }
            }
        }
    }

    for (Node* n : vnodes)
    {
        if (n->data == path[path.size() - 1])
        {
            for (Node* nod : vnodes)
            {
                if (nod->data == path[0])
                {
                    for (Edge* e : n->edges)
                    {
                        if (e->to == nod)
                        {
                            w += e->weight;
                        }
                    }
                }
            }
        }
    }

    return w;
}

void TSP::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    if (text.isEmpty()) return;

    int nodeValue = text.toInt();
    graph.addNode(nodeValue);
    ui->lineEdit->clear();
    update();
}

void TSP::on_pushButton_2_clicked()
{
    if (ui->lineEdit_2->text().isEmpty() or ui->lineEdit_3->text().isEmpty() or ui->lineEdit_4->text().isEmpty())
    {
        return;
    }
    int fromNode = ui->lineEdit_2->text().toInt();
    int toNode = ui->lineEdit_3->text().toInt();
    int weight = ui->lineEdit_4->text().toInt();
    if (graph.nodes.find(fromNode) != graph.nodes.end() && graph.nodes.find(toNode) != graph.nodes.end())
    {
        graph.addEdge(fromNode, toNode, weight);
        ui->lineEdit_2->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_3->clear();
        update();
    }
}
void TSP::on_pushButton_3_clicked()
{
    if (ui->lineEdit_5->text().isEmpty())
    {
        return;
    }
    int del = ui->lineEdit_5->text().toInt();
    graph.removeNode(del);
    ui->lineEdit_5->clear();
    update();
}
void TSP::on_pushButton_4_clicked()
{
    if (ui->lineEdit_6->text().isEmpty() or ui->lineEdit_7->text().isEmpty())
    {
        return;
    }
    int s = ui->lineEdit_6->text().toInt();
    int f = ui->lineEdit_7->text().toInt();
    graph.removeEdge(s, f);
    ui->lineEdit_7->clear();
    ui->lineEdit_6->clear();
    update();
}
void TSP::on_pushButton_5_clicked()
{
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 6, 11);
    graph.addEdge(2, 3, 12);
    graph.addEdge(2, 5, 10);
    graph.addEdge(3, 4, 16);
    graph.addEdge(4, 5, 5);
    graph.addEdge(4, 6, 9);
    graph.addEdge(5, 6, 6);

    graph.addEdge(2, 1, 8);
    graph.addEdge(6, 1, 11);
    graph.addEdge(3, 2, 12);
    graph.addEdge(5, 2, 10);
    graph.addEdge(4, 3, 16);
    graph.addEdge(5, 4, 5);
    graph.addEdge(6, 4, 9);
    graph.addEdge(6, 5, 6);
    update();
}

void TSP::on_pushButton_6_clicked()
{
    if (ui->lineEdit_8->text().isEmpty() or ui->lineEdit_9->text().isEmpty() or ui->lineEdit_10->text().isEmpty())
    {
        return;
    }
    int s = ui->lineEdit_8->text().toInt();
    int t = ui->lineEdit_9->text().toInt();
    int w = ui->lineEdit_10->text().toInt();
    graph.updateEdgeWeight(s, t, w);
    ui->lineEdit_8->text().clear();
    ui->lineEdit_9->text().clear();
    ui->lineEdit_10->text().clear();
    update();
}

void TSP::on_pushButton_7_clicked()
{
    graph.clearGraph();
    update();
}

void TSP::on_pushButton_8_clicked()
{
    ui->label_9->clear();
    ui->label_10->clear();
    ui->label_11->clear();

    if (graph.vnodes.size() == 0)
    {
        ui->label_9->setText("Невозможно решить задачу коммивояжера");
        return;
    }

    vector<int>shortestPath = graph.TSPsolve();

    if (shortestPath[0] == -1)
    {
        ui->label_9->setText("Невозможно решить задачу коммивояжера");
        return;
    }

    QString resultString;
    for (int i = 0; i < shortestPath.size(); i++)
    {
        resultString.append(QString::number(shortestPath[i]));
        if (i < shortestPath.size() - 1)
        {
            resultString.append(", ");
        }
    }
    ui->label_9->setText(resultString);
    ui->label_10->setText(QString::number(graph.way(shortestPath)));
    ui->label_11->setText("Путь: ");
    update();
}
