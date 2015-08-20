/*
 * GuiElement.h
 *
 *  Created on: Sep 2, 2013
 *      Author: Moritz Laass
 */

#ifndef GUIELEMENT_H_
#define GUIELEMENT_H_

class GuiElement {
public:
	GuiElement();
	virtual ~GuiElement();

	virtual void draw()=0;
	virtual void update()=0;


};

#endif /* GUIELEMENT_H_ */
