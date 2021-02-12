/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Entry
*/

#include <UIObject/Button.hpp>

namespace UIObject {
    class Entry : public Button {
        public:
            // Constructio of Object
            Entry();
            Entry(int id, sf::Texture &txtr, sf::Font &font, std::string def = "", sf::Vector2f pos = { 0, 0 });
            virtual ~Entry();

            // Setter
            void setMaxChar(int max = -1);

            // Getter
            sf::Text &getText();
            std::string getInput();

            // Core::Object
            void updateDisplay();
            int updateEvent(sf::RenderWindow &screen, sf::Event event);
        protected:
            // Update object
            void upSprite();
             // Drawable
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            sf::RenderTexture m_rdTxtr;
            sf::Sprite m_entry_sprt;
            std::string m_def;
            std::string m_act;
            sf::Text m_txt;
            bool m_focus;
            int m_msize;
    };
}