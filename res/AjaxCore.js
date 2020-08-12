//
// AjaxCore.js
//
// Copyright (c) 2009-2020, Applied Informatics Software Engineering GmbH.
// All rights reserved.
//
// SPDX-License-Identifier:	BSL-1.0
//


function $(id)
{
	return document.getElementById(id);
}


function $ev(event)
{
	if (event)
		return event;
	else
		return window.event;
}


function $evt(event)
{
	return event.target ? event.target : event.srcElement;
}


var AjaxCore =
{
	createPlainXMLHTTPRequest: function()
		{
			try
			{
				return new ActiveXObject("Msxml2.XMLHTTP");
			}
			catch (exc)
			{
			}
			try
			{
				return new ActiveXObject("Microsoft.XMLHTTP");
			}
			catch (exc)
			{
			}
			try
			{
				return new XMLHttpRequest();
			}
			catch (exc)
			{
			}
			return null;
		},

	createXMLHTTPRequest: function(handler)
		{
			var req = this.createPlainXMLHTTPRequest();
			if (req)
			{
				req.onreadystatechange = handler;
			}
			return req;
		},

	updateElements: function(values)
		{
			for (var key in values)
			{
				if (key == "runscript")
				{
					eval(values[key]);
				}
				else
				{
					var elem = $(key);
					if (elem)
					{
						if (elem.nodeName == "IMG")
						{
							if (elem.className == "gauge")
								elem.width = 2*values[key];
							else
								elem.src = values[key];
						}
						else
						{
							elem.innerHTML = "" + values[key];
						}
					}
				}
			}
		},

	PeriodicUpdater:
	{
		path: "",
		interval: 0,
		method: "GET",

		update: function()
			{
				var req = AjaxCore.createXMLHTTPRequest(function()
					{
						if (req.readyState == 4)
						{
							if (req.status == 200)
							{
								var values = eval("(" + req.responseText + ")");
								AjaxCore.updateElements(values);
							}
						}
					}
				);
				req.open(this.method, this.path, true);
				req.send(null);
				if (this.interval > 0)
				{
					window.setTimeout("AjaxCore.PeriodicUpdater.update()", this.interval);
				}
			},

		start: function(path, interval)
			{
				this.path = path;
				this.interval = interval;
				if (this.interval > 0)
				{
					this.update();
				}
			},

		stop: function()
			{
				this.interval = 0;
			}
	}
};
