//
//  main.cpp
//  TaskScheduler
//
//  Created by Jaime Cuartas Granada on 19/3/2024.
//

#include <iostream>
#include <vector>
#include <unordered_map>

struct Priority{
    char task;
    int leftTasks;
    int nextTimeAvailable;
    void increaseLeftTasks(){
        this->leftTasks++;
    }
    void decreaseLeftTasks(){
        this->leftTasks--;
    }
    Priority(char task): task(task), leftTasks(1), nextTimeAvailable(0) {}
};

int leastInterval(std::vector<char>& tasks, int n) {
    std::unordered_map<char, Priority*> leftTasks;
    std::vector<Priority*> leftTasksVector;
    std::unordered_map<char, Priority*>::iterator itLeftTasks;
    for(char task: tasks){
         itLeftTasks= leftTasks.find(task);
        if(itLeftTasks == leftTasks.end()){
            Priority* newPriority = new Priority(task);
            leftTasks.insert({task, newPriority});
            leftTasksVector.push_back(newPriority);
        }else{
            itLeftTasks->second->increaseLeftTasks();
        }
    }
    std::sort(leftTasksVector.begin(), leftTasksVector.end(), [](Priority* a, Priority* b){
        return a->leftTasks > b->leftTasks;
    });
    int time = 0;
    for(int i = leftTasksVector[0]->leftTasks; i>0; i--){
        std::vector<Priority*>::iterator it = leftTasksVector.begin();
        while(it!=leftTasksVector.end() && (*it)->leftTasks>0){
            time++;
            char t =(*it)->task;
            if((*it)->nextTimeAvailable>=time) {
                time=(*it)->nextTimeAvailable;
            }
            (*it)->nextTimeAvailable = time + n + 1;
            (*it)->decreaseLeftTasks();
            it++;
        }
    }
    return time;
}

int main(int argc, const char * argv[]) {
    std::vector<char> v = {'A','C','A','B','D','B'};
    std::vector<char> v2 = {'A','A','A','B','B','B'};
    //expected 12
    std::vector<char> v3 = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    
    std::cout << leastInterval(v3, 1);
    return 0;
}
