#pragma once

#ifndef ROBOT_FORMAT_HPP
#define ROBOT_FORMAT_HPP

#include <string>

namespace robot {
    
    class RobotFormat {
        
        public:
            
            static const std::string insertSpace(const int&);
            
        private:
            
            static const std::string space;
            
    };
    
}

#endif