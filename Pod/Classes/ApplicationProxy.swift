//
//  ApplicationProxy.swift
//  Pods
//
//  Created by Alexander Belyavskiy on 4/18/16.
//
//

import Foundation

@objc
public protocol ApplicationProxy {
  func openURL(url: NSURL) -> Bool
  var keyWindow: UIWindow? { get }
  func beginIgnoringInteractionEvents()
  func endIgnoringInteractionEvents()
  func isIgnoringInteractionEvents() -> Bool
  func beginBackgroundTaskWithExpirationHandler(handler: (() -> Void)?) -> UIBackgroundTaskIdentifier
  func beginBackgroundTaskWithName(taskName: String?, expirationHandler handler: (() -> Void)?) -> UIBackgroundTaskIdentifier
  func endBackgroundTask(identifier: UIBackgroundTaskIdentifier)
}