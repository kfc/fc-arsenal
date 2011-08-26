// $Id: dimageflow.js,v 1.0 2011/08/02 20:25:21 sas Exp $
(function ($) {
	Drupal.behaviors.dimageflow = {
			attach: function (context) {
				objId = Drupal.settings.dimageflow.ImageFlowID;
				refPath = Drupal.settings.dimageflow.reflectPath;
				circular = Drupal.settings.dimageflow.circular;
				imagesHeight = Drupal.settings.dimageflow.imagesheight;
				imageFocusM = Drupal.settings.dimageflow.image_focus_m;
				imagesM = Drupal.settings.dimageflow.imagesm;
				onClickFnction = new Function(Drupal.settings.dimageflow.onclick);
				var imageFlowObj = new ImageFlow();
				imageFlowObj.init({ ImageFlowID: objId, 
									reflectPath: refPath,
									circular : circular,
									imagesHeight: imagesHeight,
									imageFocusM: imageFocusM,
									onClick: onClickFnction,
									imagesM: imagesM
									});
			}
	};
})(jQuery);