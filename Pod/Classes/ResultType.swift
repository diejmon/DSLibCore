//
//  ResultType.swift
//  Pods
//
//  Created by Alexander Belyavskiy on 12/1/15.
//
//

public enum Result<T, E> {
  case Ok(T)
  case Err(E)
}

