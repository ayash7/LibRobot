#pragma once

#ifndef ROBOT_GENERATOR_HPP
#define ROBOT_GENERATOR_HPP

#include "Settings.hpp"

namespace robot {
    
    class RobotGenerator {
        
        public:
            
            RobotGenerator(const RobotSettings&, const std::string &filename = "test.robot");
            
    };
    
}

#endif