<%@ impl include="Poco/Net/NameValueCollection.h" %>
<%@ impl include="Utility.h" %>

<%%
	Poco::Net::NameValueCollection pageTemplate;
	pageTemplate.set("softwareVersion", Utility::versionString());
%>
