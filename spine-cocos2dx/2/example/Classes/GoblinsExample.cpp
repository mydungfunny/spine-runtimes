/******************************************************************************
 * Spine Runtimes Software License
 * Version 2.3
 * 
 * Copyright (c) 2013-2015, Esoteric Software
 * All rights reserved.
 * 
 * You are granted a perpetual, non-exclusive, non-sublicensable and
 * non-transferable license to use, install, execute and perform the Spine
 * Runtimes Software (the "Software") and derivative works solely for personal
 * or internal use. Without the written permission of Esoteric Software (see
 * Section 2 of the Spine Software License Agreement), you may not (a) modify,
 * translate, adapt or otherwise create derivative works, improvements of the
 * Software or develop new applications using the Software or (b) remove,
 * delete, alter or obscure any trademarks or any copyright, trademark, patent
 * or other intellectual property or proprietary rights notices on or in the
 * Software, including any copy thereof. Redistributions in binary or source
 * form must include this license and terms.
 * 
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include "GoblinsExample.h"
#include "SpineboyExample.h"
#include <iostream>
#include <fstream>
#include <string.h>

USING_NS_CC;
using namespace spine;
using namespace std;

CCScene* GoblinsExample::scene () {
	CCScene *scene = CCScene::create();
	scene->addChild(GoblinsExample::create());
	return scene;
}

bool GoblinsExample::init () {
	if (!CCLayerColor::initWithColor(ccc4(128, 128, 128, 255))) return false;

	skeletonNode = SkeletonAnimation::createWithFile("goblins-mesh.json", "goblins-mesh.atlas", 1.5f);
	skeletonNode->setAnimation(0, "walk", true);
	skeletonNode->setSkin("goblin");

	CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
	skeletonNode->setPosition(ccp(windowSize.width / 2, 20));
	addChild(skeletonNode);

	scheduleUpdate();
	setTouchEnabled(true);

	return true;
}

void GoblinsExample::ccTouchesBegan (CCSet* touches, CCEvent* event) {
	if (!skeletonNode->debugBones)
		skeletonNode->debugBones = true;
	else if (skeletonNode->timeScale == 1)
		skeletonNode->timeScale = 0.3f;
	else
		CCDirector::sharedDirector()->replaceScene(SpineboyExample::scene());
}
