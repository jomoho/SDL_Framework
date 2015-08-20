/*
 * Text.cpp
 *
 *  Created on: Aug 24, 2013
 *      Author: Moritz Laass
 */

#include "TextElement.h"
#include "App.h"

TextElement::TextElement(const string &text, SDL_Color color, int font_id,
		TextRenderType type) {
	this->font_id = font_id;
	this->type = type;
	this->color = color;

	this->text = string(text);

	tex = 0;
	src_rect.x = src_rect.y = src_rect.w = src_rect.h = 0;
	updateTexture();
}
TextElement::TextElement() {
	TextElement("", App::white);
}

TextElement::~TextElement() {
	SDL_DestroyTexture(tex);
}

int TextElement::getFontId() const {
	return font_id;
}

void TextElement::setFontId(int fontId) {
	font_id = fontId;

	updateTexture();
}

const string& TextElement::getText() const {
	return text;
}

void TextElement::setText(const string& text) {
	this->text = string(text);

	updateTexture();
}

TextRenderType TextElement::getType() const {
	return type;
}

void TextElement::setType(TextRenderType type) {
	this->type = type;

	updateTexture();
}

void TextElement::drawLeft(int x, int y, double scale, double angle) {
	if(text == ""){
		return ;
	}
	SDL_Rect dest_rect = { x, y,(int) (src_rect.w * scale),(int) (src_rect.h * scale) };
	SDL_RenderCopyEx(App::get()->ren->renderer, tex, &src_rect, &dest_rect,
			angle, NULL, SDL_FLIP_NONE);
}

void TextElement::drawRight(int x, int y, double scale) {
	if(text == ""){
		return ;
	}
	SDL_Rect dest_rect = {(int) (x - src_rect.w * scale),(int) (y - src_rect.h * scale),
			(int) (src_rect.w * scale), (int) (src_rect.h * scale)};
	SDL_RenderCopyEx(App::get()->ren->renderer, tex, &src_rect, &dest_rect, 0,
	NULL, SDL_FLIP_NONE);
}

void TextElement::drawCenter(int x, int y, double scale) {
	if(text == ""){
		return ;
	}
	SDL_Rect dest_rect ={
		(int) (x - src_rect.w * scale * 0.5),
		(int) (y - src_rect.h * scale * 0.5),
		(int) (src_rect.w * scale), (int) (src_rect.h * scale)};
	SDL_RenderCopyEx(App::get()->ren->renderer, tex, &src_rect, &dest_rect, 0,
	NULL, SDL_FLIP_NONE);
}

void TextElement::updateTexture() {
	if(text == ""){
		FILE_LOG(logDEBUG3)<<"updateTexture empty string" << this->text;
		return ;
	}

	if (tex != 0) {
		SDL_DestroyTexture(tex);
	}

	App *app = App::get();
	TTF_Font * font = app->fonts[font_id];
	SDL_Surface * srf = 0;

	if (type == 1) { //if (type == TXT_BLEND) {
		srf = TTF_RenderText_Blended(font, text.c_str(), color);
		if(srf == 0){
			FILE_LOG(logERROR) << "TTF_RenderText_Blended" << TTF_GetError();
		}
	} else {
		srf = TTF_RenderText_Solid(font, text.c_str(), color);
		
		if(srf == 0){
			FILE_LOG(logERROR) << "TTF_RenderText_Solid" << TTF_GetError();
		}

	}
	int w, h;
	TTF_SizeText(font, text.c_str(), &w, &h);
	
	src_rect.x = src_rect.y = 0;
	src_rect.w = w;
	src_rect.h = h;

	tex = SDL_CreateTextureFromSurface(App::get()->ren->renderer, srf);

	if(tex == 0){
		FILE_LOG(logERROR) << "SDL_CreateTextureFromSurface" << SDL_GetError();
	}

	SDL_FreeSurface(srf);
}
