/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Data
*/

#include "Core/Data.hpp"

namespace Core {

    /**  Public  **/

    // Construction of Object
    Data::Data(std::string config_file)
    {
		m_error = Err::Code::NONE;
        this->load(config_file);
    }

    Data::~Data() {
    }

    // Loading of Object
    Err::Code Data::load(std::string config_file)
    {
        this->clear();
        return this->addLoad(config_file);
    }

    Err::Code Data::addLoad(std::string config_file)
    {
        std::ifstream is(config_file);
        std::string line;

        if (!is.is_open()) {
            std::cerr << "[DATA]::[load] Error: fail to open file" << std::endl;
            m_error = Err::Code::INVALID_FILE;
            return m_error;
        }
        while (std::getline(is, line)) {
            if (!line.find("<img = \"") && line.find("\">", line.size() - 2)) {
				line.erase(0, 8);
				line.erase(line.size() - 2);
                m_error = this->loadImg(is, line);
            } else if (!line.find("<font = \"") && line.find("\">", line.size() - 2)) {
				line.erase(0, 9);
				line.erase(line.size() - 2);
                m_error = this->loadFont(is, line);
            } else if (line == "") {
                continue;
            } else {
                m_error = Err::Code::LINE_ERROR;
                std::cerr << "[DATA]::[load] Error: line formating" << std::endl;
            }
            if (m_error != Err::Code::NONE) {
                std::cerr << "[DATA]::[load] - End from error -" << std::endl;
                is.close();
                return m_error;
            }
        }
        is.close();
        m_error = Err::Code::NONE;
        return m_error;
    }

    // Gestion of Object
    void Data::clear()
    {
        m_txtr.clear();
        m_font.clear();
    }

    std::vector<sf::Texture> &Data::getTexture()
    {
        return m_txtr;
    }

    std::vector<sf::Font> &Data::getFont()
    {
        return m_font;
    }

    /**  Private  **/

    // Loading of Object
    Err::Code Data::loadImg(std::ifstream &is, std::string refDir)
    {
        std::string line;

        if (refDir.back() != '/') {
            refDir += '/';
        }
        std::getline(is, line);
        while (line != "</img>") {
            m_error = Tool::validityFilePath(refDir + line);
            if (m_error != Err::Code::NONE) {
                is.close();
                std::cerr << "<private> [loadImg] Error: line formating" << std::endl;
                return m_error;
            }
            m_txtr.emplace_back();
            if (!m_txtr.back().loadFromFile(refDir + line)) {
                m_txtr.pop_back();
                m_error = Err::Code::FAIL_LOAD_IMG;
                std::cerr << "<private> [loadImg] Error: loading file" << std::endl;
                return m_error;
            }
            std::getline(is, line);
        }
        return Err::Code::NONE;
    }

    Err::Code Data::loadFont(std::ifstream &is, std::string refDir)
    {
        std::string line;

        if (refDir.back() != '/') {
            refDir += '/';
        }
        std::getline(is, line);
        while (line != "</img>") {
            std::cerr << "<private> [loadFont] read > \"" << line << "\"" << std::endl;
            m_error = Tool::validityFilePath(refDir + line);
            if (m_error != Err::Code::NONE) {
                return m_error;
            }
            m_font.emplace_back();
            if (!m_font.back().loadFromFile(refDir + line)) {
                m_font.pop_back();
                m_error = Err::Code::FAIL_LOAD_FONT;
                std::cerr << "<private> [loadFont] Error: loading file" << std::endl;
                return m_error;
            }
            std::getline(is, line);
        }
        return Err::Code::NONE;
    }
}