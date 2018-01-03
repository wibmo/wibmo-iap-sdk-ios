# wibmo-iap-sdk-ios

---
In your project's podfile include under your app target ```pod 'wibmo-sdk'```


then ```pod install```


In your view controller ``` #import "WibmoSDK.h" ```

---
In your target's _Info.plist_ add

| _LSApplicationQueriesSchemes_ | Array  | (1 item)         | Env              |
| :---------------------------- | :----- | :--------------- | ---------------- |
| Item 0                        | String | payzapp          | _production_ OR  | 
| Item 0                        | String | payzappstaging   | _staging_        |


Add

| URL Types    | ``` ```        | ``` ```   | ``` ```     | ``` ```          |
| :----------- | :------------- | :-------: | :---------- | :-------------:  |
| ``` ```      | Identifier     | None      | URL Schemes | pz_MerchantID_   |
| ``` ```      | Icon           | None      | Role        | Editor           |
 
##### Eg: If your merchant ID id “34567890” then the URL Schema will be “pz34567890” 
##### Note: This is different for production/release and staging environments.

---
In your AppDelegate class check for url as follows and post appropriate notification 

```
- (BOOL)application:(UIApplication *)iApplication openURL:(NSURL *)iURL sourceApplication:(NSString *)iSourceApplication
         annotation:(id)iAnnotation {
    if (iURL && [[iURL scheme] isEqualToString:@"pz81516121"]) {
        [[NSNotificationCenter defaultCenter] postNotificationName:PROCESS_INAPP_PAYMENT object:[iURL absoluteString]];
    }
    
    return YES;
}
```

---

For more details download TestPayZapp that is available at

[https://github.com/wibmo/wibmo-iap-sdk-ios/]
