 if(std::find(actors.begin(), actors.end(), actor) != actors.end()){
                std::cout<<"Error: Tried to add multiple instances of the same actor to the system!\n";
                return;
            }

            actors.push_back(actor);