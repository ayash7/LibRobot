#pragma once

#ifndef ROBOT_SETTINGS_HPP
#define ROBOT_SETTINGS_HPP

#include "Format.hpp"

#include <list>

namespace robot {
    
    class RobotSettings {
        
        public:
            
            RobotSettings();
            
            RobotSettings &addDocumentation(const std::string&);
            
            RobotSettings &addLibrary(const std::string&);
            
            RobotSettings &withLibraryName(const std::string&);
            
            template<typename T, typename... Args>
            RobotSettings &withLibraryParameters(const T&, const Args&...);
            
            template<typename T>
            RobotSettings &withLibraryParameters(const T&);
            
            const std::list<const std::string> &getSettingsList() const;
            
        private:
            
            std::list<const std::string> settingsList;
            
            bool docStart;
            
    };
    
    template<typename T, typename... Args>
    RobotSettings &RobotSettings::withLibraryParameters(const T &t, const Args&... args) {
        
        std::string librarySettings = settingsList.back(); settingsList.pop_back();
        
        settingsList.push_back(librarySettings + RobotFormat::insertSpace(8) + t);
        
        return withLibraryParameters(args...);
        
    }
    
    template<typename T>
    RobotSettings &RobotSettings::withLibraryParameters(const T &t) {
        
        std::string librarySettings = settingsList.back(); settingsList.pop_back();
        
        settingsList.push_back(librarySettings + RobotFormat::insertSpace(8) + t);
        
        return *this;
        
    }
    
}

#endif