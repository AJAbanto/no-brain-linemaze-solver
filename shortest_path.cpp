#include <iostream>
#include <vector>

//This is a simple no-brain shortest path solver, designed to teach how a simple 
// line maze can be solved without thinking too hard
void find_shortestpath(std::vector<char> &turns_taken){
    std::vector<char> shortest_path;

    //--------- Print out input -----
    std::cout << "Input path: {";
    for(int i = 0; i < turns_taken.size(); i++){
        std::cout << turns_taken[i] << " ";
    }
    std::cout << "} \n";


    //--------- Calculate shortest path-----
    //Go through the result of the traversed map
    for(int curr_turn =0 ; curr_turn < turns_taken.size(); curr_turn++){

        //Just print out the current element
        std::cout << "Current element:" << turns_taken[curr_turn] << "\n";

        //Iterate through the next two turns, unless we've encountered the end 
        int turn_angle = 0; //This tracks the turns if we've turned 360 degrees
        for(int i = 0; i < 3 && (curr_turn + i < turns_taken.size()); i++){

            //Print out next turn
            std::cout << "Next step: " << turns_taken[curr_turn + i] << " , ";

            //Adding angles
            switch (turns_taken[curr_turn + i])
            {
            case 'L':
                turn_angle += 90;
                break;
            case 'U':
                turn_angle += 180;
                break;
            case 'R':
                turn_angle += -90;
                break;
            default:
                break;
            }
            
            std::cout << "Current turn angle: " << turn_angle << "\n";
        }

        //Check if turn angle has reached 360
        if(turn_angle == 360 || turn_angle == -360){
            //If it has, push back a "Straight" to skip the intersection 
            //that results in a 360 turn
            std::cout << "Short cut can be made\n";
            shortest_path.push_back('S');

            //Increment the iterator to skip to the next turn after the detected loop
            curr_turn += 2;
        }else{
            shortest_path.push_back(turns_taken[curr_turn]);
        }

        //If the next turn is the end then finish the loop
        if(turns_taken[curr_turn + 1] == 'E') {
            std::cout << "End of map encountered\n";
            shortest_path.push_back('E');
            break;
        }
        

        //Check if a 360 degree is achieved
    }

    
    std::cout << "Final shortest path: ";
    for(int i = 0; i < shortest_path.size(); i++){
        std::cout << shortest_path[i] << " ";
    }
    std::cout << "\n";
}

int main(){

    //Each map is represented by Chars that symbolize which action was taken
    // when an intersection was encountered
    // L means Left
    // U means U-turn
    // R means Right
    // E means End
    // S means Straight
    std::vector<char> map1= {'L', 'U', 'L', 'E'};
    std::vector<char> map2= {'L', 'U', 'L', 'R', 'L', 'U', 'L', 'E'};


    //Print shortest path
    std::cout << "------- Test Map 1 -------\n";
    find_shortestpath(map1);
    std::cout << "------- Test Map 2 -------\n";
    find_shortestpath(map2);
    return 0;
}