/**
 * IMPLEMENTACIÓN: APPLICATION CONFIG MODEL
 */

#include "application_config.hpp"

namespace Data {
    namespace Models {
        
        std::map<std::string, std::string> ApplicationConfigModel::ToMap() const {
            std::map<std::string, std::string> result;
            result["title"] = title;
            result["window_width"] = std::to_string(window_width);
            result["window_height"] = std::to_string(window_height);
            result["theme"] = theme;
            result["maximized"] = maximized ? "true" : "false";
            return result;
        }
        
        ApplicationConfigModel ApplicationConfigModel::FromMap(const std::map<std::string, std::string>& data) {
            ApplicationConfigModel config;
            
            auto it = data.find("title");
            if (it != data.end()) config.title = it->second;
            
            it = data.find("window_width");
            if (it != data.end()) config.window_width = std::stoi(it->second);
            
            it = data.find("window_height");
            if (it != data.end()) config.window_height = std::stoi(it->second);
            
            it = data.find("theme");
            if (it != data.end()) config.theme = it->second;
            
            it = data.find("maximized");
            if (it != data.end()) config.maximized = (it->second == "true");
            
            return config;
        }
        
    } // namespace Models
} // namespace Data
