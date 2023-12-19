#include "ResourceManager.h"

void ResourceManager::setFont(std::string fontKey, std::string fontName)
{

    // Check if the font with the same key already exists
    auto it = this->fonts.find(fontKey);
    if (it != this->fonts.end()) {
        std::cerr << "Font with key '" << fontKey << "' already exists.\n";
        return;
    }

    //Add a new font in our Fonts map
    sf::Font* aux_font = new sf::Font();
    if (aux_font->loadFromFile(fontName)) {
        this->fonts[fontKey] = aux_font;
    }
    else {
        //deallocate dynamic memory
        std::cerr << "Error Loading Font: '" << fontName << "'\n";
        delete aux_font;
    }

}

void ResourceManager::setTexture(std::string categoryKey, std::string textureKey, std::string texture)
{
    //Check if the texture/spritesheet with the same key already exists 
    auto it = this->textures[categoryKey].find(textureKey);
    if (it != this->textures[categoryKey].end()) {
        std::cerr << "Texture with key '" << textureKey << "' already exists.\n";
        return;
    }

    //Add a new texture(and a category if it isn't in the map already)
    sf::Texture* aux_texture = new sf::Texture();
    if (aux_texture->loadFromFile(texture)) {
        this->textures[categoryKey][textureKey] = aux_texture;
    }
    else {
        //Deallocate dynamic memory
        std::cerr << "Error loading Texture: '" << texture << "\n";
        delete aux_texture;
    }


}


void ResourceManager::initTextures()
{
    
}

void ResourceManager::initFonts()
{
    this->setFont("Gen1_2", "Resources/Fonts/1-2_Gen_Font.ttf");
    this->setFont("Gen3", "Resources/Fonts/3_Gen_Font.ttf");
    this->setFont("Gen4", "Resources/Fonts/4_Gen_Font.ttf");
    this->setFont("Gen5", "Resources/Fonts/5_Gen_Font.ttf");
    this->setFont("Gen6", "Resources/Fonts/6_Gen_Font.ttf");
}

ResourceManager::ResourceManager()
{
    this->initFonts();
}

ResourceManager::~ResourceManager()
{
}

sf::Texture* ResourceManager::getTexture(const std::string& categoryKey, const std::string& textureKey)
{
    return nullptr;
}

sf::Font* ResourceManager::getFont(const std::string& fontKey)
{
    return nullptr;
}



/*¡sf::Texture* ResourceManager::getTexture(std::string key)
{
   
}*/
